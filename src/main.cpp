#include "bn_core.h"
#include "bn_sprite_ptr.h"

#include "bn_regular_bg_items_floor.h"
#include "bn_regular_bg_items_bg.h"
#include "bn_regular_bg_ptr.h"
#include "bn_music_items.h"
#include "bn_music.h"
#include "bn_sprite_item.h"
#include "bn_log.h"
#include "bn_rect.h"
#include "bn_random.h"
#include "bn_vector.h"
#include "bn_keypad.h"
#include "bn_string.h"

#include "_ss_custom_font.h"
#include "map.h"


//assets
#include "bn_sprite_text_generator.h" 
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_particle.h"
#include "bn_sprite_items_player.h"
#include "bn_sprite_items_spike.h"
#include "bn_sprite_items_block.h"
#include "bn_sprite_items_small_spikes.h"
#include "bn_sprite_items_orb.h"
#include "bn_sprite_items_grav_orb.h"
#include "bn_sprite_items_half_block.h"

/*
todo
particles(simple)
separate player stuff from main loop
add tile index support to the obj class and py importer
attempt counter
ship mode (eventually)
*/

enum obj_type{
    SPIKE,
    BLOCK,
    ORB,
    GRAV_REVERSE_ORB
};

class Obj{
    public:
    Obj(int x, int y, int h, int w, bn::sprite_item sprite_obj, obj_type t)
    :sprite(sprite_obj.create_sprite(x,y)),
    type(t)
    {
        if (type == SPIKE){
            hitbox = bn::rect(x, y + 10, 4, 10);
        } else if (type == ORB || type == GRAV_REVERSE_ORB){
            hitbox = bn::rect(x - 2, y - 2, 20,20);
            animation = bn::create_sprite_animate_action_forever(sprite, 4, sprite_obj.tiles_item(), 0,1,2,1);
        } else {
            hitbox = bn::rect(x + 1, y, 18,16);
        }
    }

    bool shift_and_collide(int shift_amount, bn::rect player_rect){
        hitbox.set_x(hitbox.x() - shift_amount);
        sprite.set_x(hitbox.x());
        if (animation){
            animation->update();
        }
        if (hitbox.intersects(player_rect) && type != ORB && type != GRAV_REVERSE_ORB){
            return true;
        }
        return false;
    }

    bool vertical_offset(bn::rect* player_rect, bn::fixed* player_vel, bn::fixed* gravity)
    {
        if (hitbox.intersects(*player_rect)){
            if (type == SPIKE){
                return true;
            }
            if (type == ORB || type == GRAV_REVERSE_ORB){
                if(bn::keypad::a_held()){
                    if (type == ORB){
                        *player_vel = -6;
                    } else if (type == GRAV_REVERSE_ORB){
                        *gravity = -*gravity;
                    }
                    
                } 
            } else if(player_rect->y() > hitbox.y()){
                return true;
            } else {
                player_rect->set_position(player_rect->x(), hitbox.top() - player_rect->height() / 2);
            }
        }
        return false;
    }

    bool is_offscreen()
    {
        return (hitbox.x() < -140);
    }

    private:
    bn::rect hitbox;
    bn::sprite_ptr sprite;
    obj_type type;
    bn::optional<bn::sprite_animate_action<4>> animation;
};

class Particle{
    public:
    Particle(int x_pos, int y_pos, int x_v, int y_v, int grav, int life):
    sprite(bn::sprite_items::particle.create_sprite(x_pos, y_pos)),
    lifespan(life),
    gravity(grav),
    x_vel(x_v),
    y_vel(y_v)
    {
        sprite.set_z_order(-25);
    }

    void update(int speed){
        lifespan--;
        sprite.set_position(sprite.x() + x_vel - speed, sprite.y() + y_vel);
        y_vel += gravity;
    }

    bool dead(){
        return (lifespan <= 0);
    }

    private:
    bn::sprite_ptr sprite;
    int x_vel;
    int y_vel;
    int gravity;
    int lifespan;
};

class Particle_container{
    public:
    void add(int x_pos, int y_pos, int x_v, int y_v, int grav){
        if (!particles.full()){
            particles.push_back(Particle(x_pos, y_pos, x_v + RNG.get_int(4) - 2, y_v + RNG.get_int(4) - 2, grav, 15));
        }
    }

    void add(int x_pos, int y_pos, int random_level){
        if (!particles.full()){
            particles.push_back(Particle(x_pos, y_pos, RNG.get_int(random_level * 2) - random_level, RNG.get_int(random_level * 2) - random_level, 0, 15));
        }
    }

    void clear(){
        particles.clear();
    }

    void update(int speed){
        for (int i = 0; i < particles.size(); i++){
            particles[i].update(speed);
            if (particles[i].dead()){
                particles.erase(particles.begin() + i);
            }
        }
    }

    private:
    bn::vector<Particle, 50> particles;
    bn::random RNG;
};

using layer = int[5];
using sprite_vec = bn::vector<Obj, 60>;

bool shift_sprites(sprite_vec* vec, int shift, bn::rect player_rect) {
    bool ret = false;
    for (int i = 0; i < vec->size(); i++) {
        if ((*vec)[i].shift_and_collide(shift, player_rect)){
            ret = true;
        }
        if ((*vec)[i].is_offscreen()) {
            vec->erase(vec->begin() + i);
            i--; // Decrement i to adjust for the erased element
        }
    }
    return ret;
}

const int sprite_types_count = 6;

bn::sprite_item obj_ids[sprite_types_count] = {
    bn::sprite_items::spike,
    bn::sprite_items::block,
    bn::sprite_items::half_block,
    bn::sprite_items::small_spikes,
    bn::sprite_items::orb,
    bn::sprite_items::grav_orb
};

obj_type obj_types[sprite_types_count] = {
    SPIKE,
    BLOCK,
    BLOCK,
    SPIKE,
    ORB,
    GRAV_REVERSE_ORB
};

void spawn_layer(sprite_vec* vec, layer layer_data){
    for (int i = 0; i < 5; i++){
        if (layer_data[i] != -1){
            vec->push_back(Obj(140, 35 - i*16, 32, 32, obj_ids[layer_data[i]], obj_types[layer_data[i]]));
        }
    }
}

bool y_collide(bn::rect* player_rect, sprite_vec* vec, bn::fixed* player_v, bn::fixed* grav)
{
    for (int i = 0; i < vec->size(); i++) {
        if ((*vec)[i].vertical_offset(player_rect, player_v, grav)){
            return true;
        }
    }
    return false;
}


int main()
{
    bn::core::init();

    //init music
    bn::music_items::sm.play();
    bn::music::set_tempo(bn::music::tempo() * 1.9);

    //init map
    bn::regular_bg_ptr bg = bn::regular_bg_items::bg.create_bg(0,0);
    bn::regular_bg_ptr floor = bn::regular_bg_items::floor.create_bg(0,0);
    floor.set_priority(0);
    sprite_vec obstacles;
    int stage_x = 0;
    int stage_y = 0;
    int stage_layer_count = 0;
    int stage_speed = 2;
    bn::fixed gravity = 0.6;

    //const data
    const int floor_level = 35;
    const int rot_rate = 5;
    const int parallax_divisor = 2;

    //player variables
    bn::sprite_ptr player_sprite = bn::sprite_items::player.create_sprite(-30,floor_level);
    bn::rect player_hitbox = bn::rect(-30, floor_level, 16,16);
    bn::fixed player_y_vel = 1;
    bool dead = false;
    bool jumped = false;

    //player const data
    const int player_jump_speed = 7;

    //text generation variables
    int attempt_count = 1;
    bn::sprite_text_generator attempt_text = bn::sprite_text_generator(custom_font_white);
    bn::vector<bn::sprite_ptr, 10> text_sprites;
    attempt_text.generate(0,-30, "Attempt" + bn::to_string<15>(attempt_count), text_sprites);
    for (int i = 0; i < text_sprites.size(); i++){
        text_sprites[i].set_z_order(-20);
    }

    //particles
    Particle_container particles;
    

    while(true)
    {   
        particles.update(stage_speed);
        //update the player using the acceleration of gravity
        player_hitbox.set_y(player_hitbox.y() + player_y_vel.integer());
        player_y_vel += gravity;

        //buffer the y position to check if it is displaced, and see if you hit any spikes
        int buffer_y = player_hitbox.y();
        dead = y_collide(&player_hitbox, &obstacles, &player_y_vel, &gravity);
        
        //set rotation to match contacted surface or trajectory
        if (player_hitbox.y() > floor_level || buffer_y != player_hitbox.y()){
            particles.add(player_hitbox.left(), player_hitbox.bottom(), -3, -2, 0);
            particles.add(player_hitbox.left(), player_hitbox.bottom(), -3, -2, 0);
            if (player_hitbox.y() > floor_level){
                player_hitbox.set_y(floor_level);
            }
            player_y_vel = 0;
            if (jumped == true){

                //adjust the angle to the closest multiple of 90
                int new_angle = (player_sprite.rotation_angle() / bn::fixed(90)).ceil_integer() * 90;

                //make sure it is in the range 0-360
                if (new_angle < 0){
                    new_angle += 360;
                }else if (new_angle > 360){
                    new_angle -= 360;
                }
        
                player_sprite.set_rotation_angle(new_angle);
            }
            jumped = false;
        } else if (jumped == true) {
    
            //handle jump rotation
            int player_rot = player_sprite.rotation_angle().integer() - rot_rate;

            //keep it within the range 0-360
            if (player_rot < 0){
                player_rot += 360;
            }
            player_sprite.set_rotation_angle(player_rot);
        }

        //finally, update the player's sprite position
        player_sprite.set_y(player_hitbox.y());

        //update the scrolling of the background and the stage
        bg.set_x(bg.x() - stage_speed / parallax_divisor);
        floor.set_x(floor.x() - stage_speed);
        stage_x -= stage_speed;
        dead = shift_sprites(&obstacles, stage_speed, player_hitbox);

        //if it is time to spawn a new layer, create it
        if (stage_x % 16 == 0){
            //only if the level isn't over yet
            if (level_size > stage_layer_count){
                layer l = {level_array[stage_layer_count][0], level_array[stage_layer_count][1],level_array[stage_layer_count][2],level_array[stage_layer_count][3],level_array[stage_layer_count][4]};
                spawn_layer(&obstacles, l);
            }
            stage_layer_count++;
        }

        //jump if you press a
        if (bn::keypad::a_held() && jumped == false){
            jumped = true;
            player_y_vel = -player_jump_speed;
        }

        for (int i = 0; i < text_sprites.size(); i++){
            text_sprites[i].set_x(text_sprites[i].x() - stage_speed);
        }

        if(dead){
            player_sprite.set_visible(false);
            for (int i = 0; i < 30; i++){
                particles.add(player_sprite.x().integer(), player_sprite.y().integer(), 10);
            }
            for (int i = 0; i < 60; i++){
                particles.update(-2);
                bn::core::update();
            }
            player_sprite.set_visible(true);
            player_sprite.set_rotation_angle(0);

            //reset the level if you have died
            player_sprite.set_position(-30, floor_level);
            player_hitbox.set_position(-30, floor_level );
            obstacles.clear();
            stage_x = 0;
            stage_layer_count = 0;
            gravity = 0.6;
            
            //draw the attempt count
            attempt_count++;
            text_sprites.clear();
            attempt_text.generate(0,-30, "Attempt" + bn::to_string<15>(attempt_count), text_sprites);
        }

        bn::core::update();
    }
}