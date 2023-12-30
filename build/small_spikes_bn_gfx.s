
@{{BLOCK(small_spikes_bn_gfx)

@=======================================================================
@
@	small_spikes_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2023-06-14, 21:29:36
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global small_spikes_bn_gfxTiles		@ 128 unsigned chars
	.hidden small_spikes_bn_gfxTiles
small_spikes_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x02000200,0x22202220,0x22222222
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x02000200,0x02202220,0x22222222

	.section .rodata
	.align	2
	.global small_spikes_bn_gfxPal		@ 32 unsigned chars
	.hidden small_spikes_bn_gfxPal
small_spikes_bn_gfxPal:
	.hword 0x03C0,0x7FFF,0x1042,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(small_spikes_bn_gfx)
