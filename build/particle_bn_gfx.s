
@{{BLOCK(particle_bn_gfx)

@=======================================================================
@
@	particle_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2023-06-16, 19:25:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global particle_bn_gfxTiles		@ 32 unsigned chars
	.hidden particle_bn_gfxTiles
particle_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00001000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global particle_bn_gfxPal		@ 32 unsigned chars
	.hidden particle_bn_gfxPal
particle_bn_gfxPal:
	.hword 0x03E0,0x6F7B,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(particle_bn_gfx)
