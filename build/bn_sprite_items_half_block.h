#ifndef BN_SPRITE_ITEMS_HALF_BLOCK_H
#define BN_SPRITE_ITEMS_HALF_BLOCK_H

#include "bn_sprite_item.h"

//{{BLOCK(half_block_bn_gfx)

//======================================================================
//
//	half_block_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2023-06-14, 21:09:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HALF_BLOCK_BN_GFX_H
#define GRIT_HALF_BLOCK_BN_GFX_H

#define half_block_bn_gfxTilesLen 128
extern const bn::tile half_block_bn_gfxTiles[4];

#define half_block_bn_gfxPalLen 32
extern const bn::color half_block_bn_gfxPal[16];

#endif // GRIT_HALF_BLOCK_BN_GFX_H

//}}BLOCK(half_block_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item half_block(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(half_block_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(half_block_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

