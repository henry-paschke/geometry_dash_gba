#ifndef BN_SPRITE_ITEMS_GRAV_ORB_H
#define BN_SPRITE_ITEMS_GRAV_ORB_H

#include "bn_sprite_item.h"

//{{BLOCK(grav_orb_bn_gfx)

//======================================================================
//
//	grav_orb_bn_gfx, 16x48@4, 
//	+ palette 16 entries, not compressed
//	+ 12 tiles not compressed
//	Total size: 32 + 384 = 416
//
//	Time-stamp: 2023-06-16, 19:53:22
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GRAV_ORB_BN_GFX_H
#define GRIT_GRAV_ORB_BN_GFX_H

#define grav_orb_bn_gfxTilesLen 384
extern const bn::tile grav_orb_bn_gfxTiles[12];

#define grav_orb_bn_gfxPalLen 32
extern const bn::color grav_orb_bn_gfxPal[16];

#endif // GRIT_GRAV_ORB_BN_GFX_H

//}}BLOCK(grav_orb_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item grav_orb(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(grav_orb_bn_gfxTiles, 12), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(grav_orb_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

