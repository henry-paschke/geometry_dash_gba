#ifndef BN_SPRITE_ITEMS_PARTICLE_H
#define BN_SPRITE_ITEMS_PARTICLE_H

#include "bn_sprite_item.h"

//{{BLOCK(particle_bn_gfx)

//======================================================================
//
//	particle_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2023-06-16, 19:25:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PARTICLE_BN_GFX_H
#define GRIT_PARTICLE_BN_GFX_H

#define particle_bn_gfxTilesLen 32
extern const bn::tile particle_bn_gfxTiles[1];

#define particle_bn_gfxPalLen 32
extern const bn::color particle_bn_gfxPal[16];

#endif // GRIT_PARTICLE_BN_GFX_H

//}}BLOCK(particle_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item particle(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(particle_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(particle_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

