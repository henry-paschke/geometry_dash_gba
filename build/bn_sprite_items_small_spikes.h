#ifndef BN_SPRITE_ITEMS_SMALL_SPIKES_H
#define BN_SPRITE_ITEMS_SMALL_SPIKES_H

#include "bn_sprite_item.h"

//{{BLOCK(small_spikes_bn_gfx)

//======================================================================
//
//	small_spikes_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2023-06-14, 21:29:36
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SMALL_SPIKES_BN_GFX_H
#define GRIT_SMALL_SPIKES_BN_GFX_H

#define small_spikes_bn_gfxTilesLen 128
extern const bn::tile small_spikes_bn_gfxTiles[4];

#define small_spikes_bn_gfxPalLen 32
extern const bn::color small_spikes_bn_gfxPal[16];

#endif // GRIT_SMALL_SPIKES_BN_GFX_H

//}}BLOCK(small_spikes_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item small_spikes(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(small_spikes_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(small_spikes_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

