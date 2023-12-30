#ifndef BN_SPRITE_ITEMS_ORB_H
#define BN_SPRITE_ITEMS_ORB_H

#include "bn_sprite_item.h"

//{{BLOCK(orb_bn_gfx)

//======================================================================
//
//	orb_bn_gfx, 16x48@4, 
//	+ palette 16 entries, not compressed
//	+ 12 tiles not compressed
//	Total size: 32 + 384 = 416
//
//	Time-stamp: 2023-06-15, 16:08:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ORB_BN_GFX_H
#define GRIT_ORB_BN_GFX_H

#define orb_bn_gfxTilesLen 384
extern const bn::tile orb_bn_gfxTiles[12];

#define orb_bn_gfxPalLen 32
extern const bn::color orb_bn_gfxPal[16];

#endif // GRIT_ORB_BN_GFX_H

//}}BLOCK(orb_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item orb(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(orb_bn_gfxTiles, 12), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(orb_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

