#ifndef BN_REGULAR_BG_ITEMS_BG_H
#define BN_REGULAR_BG_ITEMS_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_bn_gfx)

//======================================================================
//
//	bg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 90 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2880 + 2048 = 4960
//
//	Time-stamp: 2023-06-13, 20:54:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_BN_GFX_H
#define GRIT_BG_BN_GFX_H

#define bg_bn_gfxTilesLen 2880
extern const bn::tile bg_bn_gfxTiles[90];

#define bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_bn_gfxMap[1024];

#define bg_bn_gfxPalLen 32
extern const bn::color bg_bn_gfxPal[16];

#endif // GRIT_BG_BN_GFX_H

//}}BLOCK(bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg(
            regular_bg_tiles_item(span<const tile>(bg_bn_gfxTiles, 90), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

