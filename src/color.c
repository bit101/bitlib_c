#include <cairo.h>
#include <math.h>
#include <stdlib.h>
#include "bitlib.h"

bl_color* bl_color_rgba(double r, double g, double b, double a) {
  bl_color* c = malloc(sizeof(bl_color));
  c->r = r;
  c->g = g;
  c->b = b;
  c->a = a;
  return c;
}

bl_color* bl_color_rgb(double r, double g, double b) {
  return bl_color_rgba(r, g, b, 1.0);
}

bl_color* bl_color_rgba_int(int r, int g, int b, int a) {
  return bl_color_rgba(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

bl_color* bl_color_rgb_int(int r, int g, int b) {
  return bl_color_rgba_int(r, g, b, 255);
}

bl_color* bl_color_int_24(int value) {
  int r = value >> 16 & 0xff;
  int g = value >> 8 & 0xff;
  int b = value & 0xff;
  return bl_color_rgb_int(r, g, b);
}

bl_color* bl_color_int_32(int value) {
  int a = value >> 24;
  int r = value >> 16 & 0xff;
  int g = value >> 8 & 0xff;
  int b = value & 0xff;
  return bl_color_rgba_int(r, g, b, a);
}

bl_color* bl_color_lerp(bl_color* color_a, bl_color* color_b, double t) {
  double r = color_a->r + (color_b->r - color_a->r) * t;
  double g = color_a->g + (color_b->g - color_a->g) * t;
  double b = color_a->b + (color_b->b - color_a->b) * t;
  double a = color_a->a + (color_b->a - color_a->a) * t;
  return bl_color_rgba(r, g, b, a);
}

bl_color* bl_color_random_rgb() {
  double r = rand_double();
  double g = rand_double();
  double b = rand_double();
  return bl_color_rgb(r, g, b);
}

bl_color* bl_color_hsv(double h, double s, double v) {
  h = h / 360.0;
  s = bl_clamp(s, 0, 1);
  v = bl_clamp(v, 0, 1);
  double i = floor(h * 6.0);
  double f = h * 6.0 - i;
  double p = v * (1.0 - s);
  double q = v * (1.0 - f * s);
  double t = v * (1.0 - (1.0 - f) * s);

  switch ((int)i % 6) {
    case 0:
      return bl_color_rgb(v, t, p);
    case 1:
      return bl_color_rgb(q, v, p);
    case 2:
      return bl_color_rgb(p, v, t);
    case 3:
      return bl_color_rgb(p, q, v);
    case 4:
      return bl_color_rgb(t, p, v);
    case 5:
      return bl_color_rgb(v, p, q);
    default:
      return bl_color_rgb(0.0, 0.0, 0.0);
  }
}

bl_color* bl_color_grey(double shade) {
  return bl_color_rgb(shade, shade, shade);
}

bl_color* bl_color_grey_int(int shade) {
  return bl_color_grey(shade / 255.0);
}

bl_color* bl_color_random_grey() {
  return bl_color_grey(rand_double());
}

bl_color* bl_color_random_grey_range(double min, double max) {
  return bl_color_grey(min + rand_double() * (max - min));
}

bl_color* bl_color_blueviolet() {
  return bl_color_rgb_int(138, 43, 226);
}

bl_color* bl_color_brown() {
  return bl_color_rgb_int(165, 42, 42);
}

bl_color* bl_color_aliceblue() {
  return bl_color_rgb_int(240, 248, 255);
}

bl_color* bl_color_antiquewhite() {
  return bl_color_rgb_int(250, 235, 215);
}

bl_color* bl_color_aqua() {
  return bl_color_rgb_int(0, 255, 255);
}

bl_color* bl_color_aquamarine() {
  return bl_color_rgb_int(127, 255, 212);
}

bl_color* bl_color_azure() {
  return bl_color_rgb_int(240, 255, 255);
}

bl_color* bl_color_beige() {
  return bl_color_rgb_int(245, 245, 220);
}

bl_color* bl_color_bisque() {
  return bl_color_rgb_int(255, 228, 196);
}

bl_color* bl_color_black() {
  return bl_color_rgb_int(0, 0, 0);
}

bl_color* bl_color_blanchedalmond() {
  return bl_color_rgb_int(255, 235, 205);
}

bl_color* bl_color_blue() {
  return bl_color_rgb_int(0, 0, 255);
}

bl_color* bl_color_burlywood() {
  return bl_color_rgb_int(222, 184, 135);
}

bl_color* bl_color_cadetblue() {
  return bl_color_rgb_int(95, 158, 160);
}

bl_color* bl_color_chartreuse() {
  return bl_color_rgb_int(127, 255, 0);
}

bl_color* bl_color_chocolate() {
  return bl_color_rgb_int(210, 105, 30);
}

bl_color* bl_color_coral() {
  return bl_color_rgb_int(255, 127, 80);
}

bl_color* bl_color_cornflowerblue() {
  return bl_color_rgb_int(100, 149, 237);
}

bl_color* bl_color_cornsilk() {
  return bl_color_rgb_int(255, 248, 220);
}

bl_color* bl_color_crimson() {
  return bl_color_rgb_int(220, 20, 60);
}

bl_color* bl_color_cyan() {
  return bl_color_rgb_int(0, 255, 255);
}

bl_color* bl_color_darkblue() {
  return bl_color_rgb_int(0, 0, 139);
}

bl_color* bl_color_darkcyan() {
  return bl_color_rgb_int(0, 139, 139);
}

bl_color* bl_color_darkgoldenrod() {
  return bl_color_rgb_int(184, 134, 11);
}

bl_color* bl_color_darkgray() {
  return bl_color_rgb_int(169, 169, 169);
}

bl_color* bl_color_darkgreen() {
  return bl_color_rgb_int(0, 100, 0);
}

bl_color* bl_color_darkgrey() {
  return bl_color_rgb_int(169, 169, 169);
}

bl_color* bl_color_darkkhaki() {
  return bl_color_rgb_int(189, 183, 107);
}

bl_color* bl_color_darkmagenta() {
  return bl_color_rgb_int(139, 0, 139);
}

bl_color* bl_color_darkolivegreen() {
  return bl_color_rgb_int(85, 107, 47);
}

bl_color* bl_color_darkorange() {
  return bl_color_rgb_int(255, 140, 0);
}

bl_color* bl_color_darkorchid() {
  return bl_color_rgb_int(153, 50, 204);
}

bl_color* bl_color_darkred() {
  return bl_color_rgb_int(139, 0, 0);
}

bl_color* bl_color_darksalmon() {
  return bl_color_rgb_int(233, 150, 122);
}

bl_color* bl_color_darkseagreen() {
  return bl_color_rgb_int(143, 188, 143);
}

bl_color* bl_color_darkslateblue() {
  return bl_color_rgb_int(72, 61, 139);
}

bl_color* bl_color_darkslategray() {
  return bl_color_rgb_int(47, 79, 79);
}

bl_color* bl_color_darkslategrey() {
  return bl_color_rgb_int(47, 79, 79);
}

bl_color* bl_color_darkturquoise() {
  return bl_color_rgb_int(0, 206, 209);
}

bl_color* bl_color_darkviolet() {
  return bl_color_rgb_int(148, 0, 211);
}

bl_color* bl_color_deeppink() {
  return bl_color_rgb_int(255, 20, 147);
}

bl_color* bl_color_deepskyblue() {
  return bl_color_rgb_int(0, 191, 255);
}

bl_color* bl_color_dimgray() {
  return bl_color_rgb_int(105, 105, 105);
}

bl_color* bl_color_dimgrey() {
  return bl_color_rgb_int(105, 105, 105);
}

bl_color* bl_color_dodgerblue() {
  return bl_color_rgb_int(30, 144, 255);
}

bl_color* bl_color_firebrick() {
  return bl_color_rgb_int(178, 34, 34);
}

bl_color* bl_color_floralwhite() {
  return bl_color_rgb_int(255, 250, 240);
}

bl_color* bl_color_forestgreen() {
  return bl_color_rgb_int(34, 139, 34);
}

bl_color* bl_color_fuchsia() {
  return bl_color_rgb_int(255, 0, 255);
}

bl_color* bl_color_gainsboro() {
  return bl_color_rgb_int(220, 220, 220);
}

bl_color* bl_color_ghostwhite() {
  return bl_color_rgb_int(248, 248, 255);
}

bl_color* bl_color_gold() {
  return bl_color_rgb_int(255, 215, 0);
}

bl_color* bl_color_goldenrod() {
  return bl_color_rgb_int(218, 165, 32);
}

bl_color* bl_color_gray() {
  return bl_color_rgb_int(128, 128, 128);
}

bl_color* bl_color_green() {
  return bl_color_rgb_int(0, 128, 0);
}

bl_color* bl_color_greenyellow() {
  return bl_color_rgb_int(173, 255, 47);
}

bl_color* bl_color_honeydew() {
  return bl_color_rgb_int(240, 255, 240);
}

bl_color* bl_color_hotpink() {
  return bl_color_rgb_int(255, 105, 180);
}

bl_color* bl_color_indianred() {
  return bl_color_rgb_int(205, 92, 92);
}

bl_color* bl_color_indigo() {
  return bl_color_rgb_int(75, 0, 130);
}

bl_color* bl_color_ivory() {
  return bl_color_rgb_int(255, 255, 240);
}

bl_color* bl_color_khaki() {
  return bl_color_rgb_int(240, 230, 140);
}

bl_color* bl_color_lavender() {
  return bl_color_rgb_int(230, 230, 250);
}

bl_color* bl_color_lavenderblush() {
  return bl_color_rgb_int(255, 240, 245);
}

bl_color* bl_color_lawngreen() {
  return bl_color_rgb_int(124, 252, 0);
}

bl_color* bl_color_lemonchiffon() {
  return bl_color_rgb_int(255, 250, 205);
}

bl_color* bl_color_lightblue() {
  return bl_color_rgb_int(173, 216, 230);
}

bl_color* bl_color_lightcoral() {
  return bl_color_rgb_int(240, 128, 128);
}

bl_color* bl_color_lightcyan() {
  return bl_color_rgb_int(224, 255, 255);
}

bl_color* bl_color_lightgoldenrodyellow() {
  return bl_color_rgb_int(250, 250, 210);
}

bl_color* bl_color_lightgray() {
  return bl_color_rgb_int(211, 211, 211);
}

bl_color* bl_color_lightgreen() {
  return bl_color_rgb_int(144, 238, 144);
}

bl_color* bl_color_lightgrey() {
  return bl_color_rgb_int(211, 211, 211);
}

bl_color* bl_color_lightpink() {
  return bl_color_rgb_int(255, 182, 193);
}

bl_color* bl_color_lightsalmon() {
  return bl_color_rgb_int(255, 160, 122);
}

bl_color* bl_color_lightseagreen() {
  return bl_color_rgb_int(32, 178, 170);
}

bl_color* bl_color_lightskyblue() {
  return bl_color_rgb_int(135, 206, 250);
}

bl_color* bl_color_lightslategray() {
  return bl_color_rgb_int(119, 136, 153);
}

bl_color* bl_color_lightslategrey() {
  return bl_color_rgb_int(119, 136, 153);
}

bl_color* bl_color_lightsteelblue() {
  return bl_color_rgb_int(176, 196, 222);
}

bl_color* bl_color_lightyellow() {
  return bl_color_rgb_int(255, 255, 224);
}

bl_color* bl_color_lime() {
  return bl_color_rgb_int(0, 255, 0);
}

bl_color* bl_color_limegreen() {
  return bl_color_rgb_int(50, 205, 50);
}

bl_color* bl_color_linen() {
  return bl_color_rgb_int(250, 240, 230);
}

bl_color* bl_color_magenta() {
  return bl_color_rgb_int(255, 0, 255);
}

bl_color* bl_color_maroon() {
  return bl_color_rgb_int(128, 0, 0);
}

bl_color* bl_color_mediumaquamarine() {
  return bl_color_rgb_int(102, 205, 170);
}

bl_color* bl_color_mediumblue() {
  return bl_color_rgb_int(0, 0, 205);
}

bl_color* bl_color_mediumorchid() {
  return bl_color_rgb_int(186, 85, 211);
}

bl_color* bl_color_mediumpurple() {
  return bl_color_rgb_int(147, 112, 219);
}

bl_color* bl_color_mediumseagreen() {
  return bl_color_rgb_int(60, 179, 113);
}

bl_color* bl_color_mediumslateblue() {
  return bl_color_rgb_int(123, 104, 238);
}

bl_color* bl_color_mediumspringgreen() {
  return bl_color_rgb_int(0, 250, 154);
}

bl_color* bl_color_mediumturquoise() {
  return bl_color_rgb_int(72, 209, 204);
}

bl_color* bl_color_mediumvioletred() {
  return bl_color_rgb_int(199, 21, 133);
}

bl_color* bl_color_midnightblue() {
  return bl_color_rgb_int(25, 25, 112);
}

bl_color* bl_color_mintcream() {
  return bl_color_rgb_int(245, 255, 250);
}

bl_color* bl_color_mistyrose() {
  return bl_color_rgb_int(255, 228, 225);
}

bl_color* bl_color_moccasin() {
  return bl_color_rgb_int(255, 228, 181);
}

bl_color* bl_color_navajowhite() {
  return bl_color_rgb_int(255, 222, 173);
}

bl_color* bl_color_navy() {
  return bl_color_rgb_int(0, 0, 128);
}

bl_color* bl_color_oldlace() {
  return bl_color_rgb_int(253, 245, 230);
}

bl_color* bl_color_olive() {
  return bl_color_rgb_int(128, 128, 0);
}

bl_color* bl_color_olivedrab() {
  return bl_color_rgb_int(107, 142, 35);
}

bl_color* bl_color_orange() {
  return bl_color_rgb_int(255, 165, 0);
}

bl_color* bl_color_orangered() {
  return bl_color_rgb_int(255, 69, 0);
}

bl_color* bl_color_orchid() {
  return bl_color_rgb_int(218, 112, 214);
}

bl_color* bl_color_palegoldenrod() {
  return bl_color_rgb_int(238, 232, 170);
}

bl_color* bl_color_palegreen() {
  return bl_color_rgb_int(152, 251, 152);
}

bl_color* bl_color_paleturquoise() {
  return bl_color_rgb_int(175, 238, 238);
}

bl_color* bl_color_palevioletred() {
  return bl_color_rgb_int(219, 112, 147);
}

bl_color* bl_color_papayawhip() {
  return bl_color_rgb_int(255, 239, 213);
}

bl_color* bl_color_peachpuff() {
  return bl_color_rgb_int(255, 218, 185);
}

bl_color* bl_color_peru() {
  return bl_color_rgb_int(205, 133, 63);
}

bl_color* bl_color_pink() {
  return bl_color_rgb_int(255, 192, 203);
}

bl_color* bl_color_plum() {
  return bl_color_rgb_int(221, 160, 221);
}

bl_color* bl_color_powderblue() {
  return bl_color_rgb_int(176, 224, 230);
}

bl_color* bl_color_purple() {
  return bl_color_rgb_int(128, 0, 128);
}

bl_color* bl_color_rebeccapurple() {
  return bl_color_rgb_int(102, 51, 153);
}

bl_color* bl_color_red() {
  return bl_color_rgb_int(255, 0, 0);
}

bl_color* bl_color_rosybrown() {
  return bl_color_rgb_int(188, 143, 143);
}

bl_color* bl_color_royalblue() {
  return bl_color_rgb_int(65, 105, 225);
}

bl_color* bl_color_saddlebrown() {
  return bl_color_rgb_int(139, 69, 19);
}

bl_color* bl_color_salmon() {
  return bl_color_rgb_int(250, 128, 114);
}

bl_color* bl_color_sandybrown() {
  return bl_color_rgb_int(244, 164, 96);
}

bl_color* bl_color_seagreen() {
  return bl_color_rgb_int(46, 139, 87);
}

bl_color* bl_color_seashell() {
  return bl_color_rgb_int(255, 245, 238);
}

bl_color* bl_color_sienna() {
  return bl_color_rgb_int(160, 82, 45);
}

bl_color* bl_color_silver() {
  return bl_color_rgb_int(192, 192, 192);
}

bl_color* bl_color_skyblue() {
  return bl_color_rgb_int(135, 206, 235);
}

bl_color* bl_color_slateblue() {
  return bl_color_rgb_int(106, 90, 205);
}

bl_color* bl_color_slategray() {
  return bl_color_rgb_int(112, 128, 144);
}

bl_color* bl_color_slategrey() {
  return bl_color_rgb_int(112, 128, 144);
}

bl_color* bl_color_snow() {
  return bl_color_rgb_int(255, 250, 250);
}

bl_color* bl_color_springgreen() {
  return bl_color_rgb_int(0, 255, 127);
}

bl_color* bl_color_steelblue() {
  return bl_color_rgb_int(70, 130, 180);
}

bl_color* bl_color_tan() {
  return bl_color_rgb_int(210, 180, 140);
}

bl_color* bl_color_teal() {
  return bl_color_rgb_int(0, 128, 128);
}

bl_color* bl_color_thistle() {
  return bl_color_rgb_int(216, 191, 216);
}

bl_color* bl_color_tomato() {
  return bl_color_rgb_int(255, 99, 71);
}

bl_color* bl_color_turquoise() {
  return bl_color_rgb_int(64, 224, 208);
}

bl_color* bl_color_violet() {
  return bl_color_rgb_int(238, 130, 238);
}

bl_color* bl_color_wheat() {
  return bl_color_rgb_int(245, 222, 179);
}

bl_color* bl_color_white() {
  return bl_color_rgb_int(255, 255, 255);
}

bl_color* bl_color_whitesmoke() {
  return bl_color_rgb_int(245, 245, 245);
}

bl_color* bl_color_yellow() {
  return bl_color_rgb_int(255, 255, 0);
}

bl_color* bl_color_yellowgreen() {
  return bl_color_rgb_int(154, 205, 50);
}
