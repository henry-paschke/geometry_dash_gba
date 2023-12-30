
@{{BLOCK(spike_bn_gfx)

@=======================================================================
@
@	spike_bn_gfx, 16x16@4, 
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
	.global spike_bn_gfxTiles		@ 128 unsigned chars
	.hidden spike_bn_gfxTiles
spike_bn_gfxTiles:
	.word 0x10000000,0x21000000,0x21000000,0x22100000,0x22100000,0x22210000,0x22210000,0x44441000
	.word 0x00000000,0x00000001,0x00000001,0x00000012,0x00000012,0x00000122,0x00000122,0x00001444
	.word 0x44441000,0x33333100,0x33333100,0x33333310,0x55555510,0x55555551,0x55555551,0x11111111
	.word 0x00001444,0x00013333,0x00013333,0x00133333,0x00155555,0x01555555,0x01555555,0x11111111

	.section .rodata
	.align	2
	.global spike_bn_gfxPal		@ 32 unsigned chars
	.hidden spike_bn_gfxPal
spike_bn_gfxPal:
	.hword 0x03E0,0x7FFF,0x1023,0x0421,0x0821,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(spike_bn_gfx)
