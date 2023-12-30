#ifndef _SS_8x8_SPRITE_FONT_H
#define _SS_8x8_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_variable_8x8_font.h"
#include "bn_sprite_items_white_font.h"

constexpr bn::utf8_character variable_8x8_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"
};

constexpr int8_t variable_8x8_sprite_font_character_widths[] = {
    4,  // 32
    2,  // 33 !
    6,  // 34 "
    7,  // 35 #
    8,  // 36 $
    8,  // 37 %
    8,  // 38 &
    3,  // 39 '
    4,  // 40 (
    4,  // 41 )
    6,  // 42 *
    7,  // 43 +
    3,  // 44 ,
    5,  // 45 -
    2,  // 46 .
    8,  // 47 /
    5,  // 48 0
    5,  // 49 1
    5,  // 50 2
    5,  // 51 3
    5,  // 52 4
    5,  // 53 5
    5,  // 54 6
    5,  // 55 7
    5,  // 56 8
    5,  // 57 9
    3,  // 58 :
    3,  // 59 ;
    7,  // 60 <
    7,  // 61 =
    7,  // 62 >
    7,  // 63 ?
    8,  // 64 @
    5,  // 65 A
    5,  // 66 B
    5,  // 65 C
    5,  // 68 D
    5,  // 69 E
    5,  // 50 F
    5,  // 51 G
    5,  // 52 H
    4,  // 53 I
    5,  // 74 J
    5,  // 75 K
    5,  // 76 L
    6,  // 77 M
    5,  // 78 N
    5,  // 79 O
    5,  // 80 P
    6,  // 81 Q
    5,  // 82 R
    5,  // 83 S
    5,  // 84 T
    5,  // 85 U
    6,  // 86 V
    6,  // 87 W
    5,  // 88 X
    5,  // 89 Y
    5,  // 90 Z
    4,  // 91 [
    8,  // 92
    4,  // 93 ]
    7,  // 94 ^
    7,  // 95 _
    3,  // 96 `
    4,  // 97 a
    4,  // 98 b
    4,  // 99 c
    4,  // 100 d
    4,  // 101 e
    4,  // 102 f
    4,  // 103 g
    4,  // 104 h
    4,  // 105 i
    4,  // 106 j
    4,  // 107 k
    4,  // 108 l
    6,  // 109 m
    4,  // 110 n
    4,  // 111 o
    4,  // 112 p
    4,  // 113 q
    4,  // 114 r
    4,  // 115 s
    5,  // 116 t
    5,  // 117 u
    5,  // 118 v
    6,  // 119 w
    4,  // 120 x
    4,  // 121 y
    4,  // 122 z
    4,  // 123 {
    2,  // 124 |
    4,  // 125 }
    8,  // 126 ~
    7,  // Á
    6,  // É
    7,  // Í
    7,  // Ó
    7,  // Ú
    7,  // Ü
    7,  // Ñ
    5,  // á
    5,  // é
    5,  // í
    5,  // ó
    6,  // ú
    6,  // ü
    5,  // ñ
    3,  // ¡
    7,  // ¿
};


constexpr bn::span<const bn::utf8_character> variable_8x8_sprite_font_utf8_characters_span(
        variable_8x8_sprite_font_utf8_characters);

constexpr auto variable_8x8_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<variable_8x8_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font custom_font(
        bn::sprite_items::variable_8x8_font, variable_8x8_sprite_font_utf8_characters_map.reference(),
        variable_8x8_sprite_font_character_widths);

constexpr bn::sprite_font custom_font_white(
        bn::sprite_items::white_font, variable_8x8_sprite_font_utf8_characters_map.reference(),
        variable_8x8_sprite_font_character_widths);

#endif
