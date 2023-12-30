
@{{BLOCK(block_bn_gfx)

@=======================================================================
@
@	block_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2023-06-14, 21:09:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global block_bn_gfxTiles		@ 128 unsigned chars
	.hidden block_bn_gfxTiles
block_bn_gfxTiles:
	.word 0x11111111,0x22222221,0x22222221,0x22222221,0x22222221,0x22222221,0x22222221,0x22222221
	.word 0x11111111,0x12222222,0x12222222,0x12222222,0x12222222,0x12222222,0x12222222,0x12222222
	.word 0x22222221,0x22222221,0x22222221,0x22222221,0x22222221,0x22222221,0x22222221,0x11111111
	.word 0x12222222,0x12222222,0x12222222,0x12222222,0x12222222,0x12222222,0x12222222,0x11111111

	.section .rodata
	.align	2
	.global block_bn_gfxPal		@ 32 unsigned chars
	.hidden block_bn_gfxPal
block_bn_gfxPal:
	.hword 0x03C0,0x7FFF,0x1042,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(block_bn_gfx)
