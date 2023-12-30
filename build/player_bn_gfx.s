
@{{BLOCK(player_bn_gfx)

@=======================================================================
@
@	player_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2023-06-14, 19:41:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global player_bn_gfxTiles		@ 128 unsigned chars
	.hidden player_bn_gfxTiles
player_bn_gfxTiles:
	.word 0x22222222,0x11111112,0x11222212,0x11233212,0x11233212,0x11222212,0x11111112,0x11111112
	.word 0x22222222,0x21111111,0x21122221,0x21123321,0x21123321,0x21122221,0x21111111,0x21111111
	.word 0x11111112,0x11111112,0x22222212,0x33333212,0x22222212,0x11111112,0x11111112,0x22222222
	.word 0x21111111,0x21111111,0x21222222,0x21233333,0x21222222,0x21111111,0x21111111,0x22222222

	.section .rodata
	.align	2
	.global player_bn_gfxPal		@ 32 unsigned chars
	.hidden player_bn_gfxPal
player_bn_gfxPal:
	.hword 0x03E0,0x035B,0x0000,0x6400,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(player_bn_gfx)
