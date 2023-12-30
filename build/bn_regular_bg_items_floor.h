#ifndef BN_REGULAR_BG_ITEMS_FLOOR_H
#define BN_REGULAR_BG_ITEMS_FLOOR_H

#include "bn_regular_bg_item.h"

//{{BLOCK(floor_bn_gfx)

//======================================================================
//
//	floor_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 31 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 992 + 2048 = 3072
//
//	Time-stamp: 2023-06-13, 20:11:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLOOR_BN_GFX_H
#define GRIT_FLOOR_BN_GFX_H

#define floor_bn_gfxTilesLen 992
extern const bn::tile floor_bn_gfxTiles[31];

#define floor_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell floor_bn_gfxMap[1024];

#define floor_bn_gfxPalLen 32
extern const bn::color floor_bn_gfxPal[16];

#endif // GRIT_FLOOR_BN_GFX_H

//}}BLOCK(floor_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item floor(
            regular_bg_tiles_item(span<const tile>(floor_bn_gfxTiles, 31), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(floor_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(floor_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

