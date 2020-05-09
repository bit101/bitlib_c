#include <gtk/gtk.h>
#include <malloc.h>
#include <math.h>
#include "color.h"


color* color_rgba(double r, double g, double b, double a)
{
  color *c = malloc(sizeof(color));
  c->r = r;
  c->g = g;
  c->b = b;
  c->a = a;
  return c;
}

color* color_rgb(double r, double g, double b)
{
  return color_rgba(r, g, b, 1.0);
}

color* color_rgba_int(int r, int g, int b, int a)
{
  return color_rgba(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

color* color_rgb_int(int r, int g, int b)
{
  return color_rgba_int(r, g, b, 255);
}

color* color_int_24(int value)
{
  int r = value >> 16 & 0xff;
  int g = value >> 8 & 0xff;
  int b = value & 0xff;
  return color_rgb_int(r, g, b);
}

color* color_int_32(int value)
{
  int a = value >> 24;
  int r = value >> 16 & 0xff;
  int g = value >> 8 & 0xff;
  int b = value & 0xff;
  return color_rgba_int(r, g, b, a);
}

color* color_lerp(color *color_a, color *color_b, double t)
{
  double r = color_a->r + (color_b->r - color_a->r) * t;
  double g = color_a->g + (color_b->g - color_a->g) * t;
  double b = color_a->b + (color_b->b - color_a->b) * t;
  double a = color_a->a + (color_b->a - color_a->a) * t;
  return color_rgba(r, g, b, a);

}

color* color_random_rgb()
{
  double r = g_random_double();
  double g = g_random_double();
  double b = g_random_double();
  return color_rgb(r, g, b);
}

color* color_hsv(double h, double s, double v)
{
  h = h / 360.0;
  double i = floor(h * 6.0);
  double f = h * 6.0 - i;
  double p = v * (1.0 - s);
  double q = v * (1.0 - f * s);
  double t = v * (1.0 - (1.0 - f) * s);

  switch ((int)i % 6) {
    case 0:
      return color_rgb(v, t, p);
    case 1:
      return color_rgb(q, v, p);
    case 2:
      return color_rgb(p, v, t);
    case 3:
      return color_rgb(p, q, v);
    case 4:
      return color_rgb(t, p, v);
    case 5:
      return color_rgb(v, p, q);
    default:
      return color_rgb(0.0, 0.0, 0.0);
  }
}

color* color_grey(double shade)
{
  return color_rgb(shade, shade, shade);
}

color* color_grey_int(int shade)
{
  return color_grey(shade / 255.0);
}

color* color_random_grey()
{
  return color_grey(g_random_double());
}

color* color_random_grey_range(double min, double max)
{
  return color_grey(min + g_random_double() * (max - min));
}



color* color_blueviolet() { return color_rgb_int(138, 43, 226);}

color* color_brown() { return color_rgb_int(165, 42, 42);}

color* color_aliceblue() { return color_rgb_int(240, 248, 255);}

color* color_antiquewhite() { return color_rgb_int(250, 235, 215);}

color* color_aqua() { return color_rgb_int(0, 255, 255);}

color* color_aquamarine() { return color_rgb_int(127, 255, 212);}

color* color_azure() { return color_rgb_int(240, 255, 255);}

color* color_beige() { return color_rgb_int(245, 245, 220);}

color* color_bisque() { return color_rgb_int(255, 228, 196);}

color* color_black() { return color_rgb_int(0, 0, 0);}

color* color_blanchedalmond() { return color_rgb_int(255, 235, 205);}

color* color_blue() { return color_rgb_int(0, 0, 255);}

color* color_burlywood() { return color_rgb_int(222, 184, 135);}

color* color_cadetblue() { return color_rgb_int(95, 158, 160);}

color* color_chartreuse() { return color_rgb_int(127, 255, 0);}

color* color_chocolate() { return color_rgb_int(210, 105, 30);}

color* color_coral() { return color_rgb_int(255, 127, 80);}

color* color_cornflowerblue() { return color_rgb_int(100, 149, 237);}

color* color_cornsilk() { return color_rgb_int(255, 248, 220);}

color* color_crimson() { return color_rgb_int(220, 20, 60);}

color* color_cyan() { return color_rgb_int(0, 255, 255);}

color* color_darkblue() { return color_rgb_int(0, 0, 139);}

color* color_darkcyan() { return color_rgb_int(0, 139, 139);}

color* color_darkgoldenrod() { return color_rgb_int(184, 134, 11);}

color* color_darkgray() { return color_rgb_int(169, 169, 169);}

color* color_darkgreen() { return color_rgb_int(0, 100, 0);}

color* color_darkgrey() { return color_rgb_int(169, 169, 169);}

color* color_darkkhaki() { return color_rgb_int(189, 183, 107);}

color* color_darkmagenta() { return color_rgb_int(139, 0, 139);}

color* color_darkolivegreen() { return color_rgb_int(85, 107, 47);}

color* color_darkorange() { return color_rgb_int(255, 140, 0);}

color* color_darkorchid() { return color_rgb_int(153, 50, 204);}

color* color_darkred() { return color_rgb_int(139, 0, 0);}

color* color_darksalmon() { return color_rgb_int(233, 150, 122);}

color* color_darkseagreen() { return color_rgb_int(143, 188, 143);}

color* color_darkslateblue() { return color_rgb_int(72, 61, 139);}

color* color_darkslategray() { return color_rgb_int(47, 79, 79);}

color* color_darkslategrey() { return color_rgb_int(47, 79, 79);}

color* color_darkturquoise() { return color_rgb_int(0, 206, 209);}

color* color_darkviolet() { return color_rgb_int(148, 0, 211);}

color* color_deeppink() { return color_rgb_int(255, 20, 147);}

color* color_deepskyblue() { return color_rgb_int(0, 191, 255);}

color* color_dimgray() { return color_rgb_int(105, 105, 105);}

color* color_dimgrey() { return color_rgb_int(105, 105, 105);}

color* color_dodgerblue() { return color_rgb_int(30, 144, 255);}

color* color_firebrick() { return color_rgb_int(178, 34, 34);}

color* color_floralwhite() { return color_rgb_int(255, 250, 240);}

color* color_forestgreen() { return color_rgb_int(34, 139, 34);}

color* color_fuchsia() { return color_rgb_int(255, 0, 255);}

color* color_gainsboro() { return color_rgb_int(220, 220, 220);}

color* color_ghostwhite() { return color_rgb_int(248, 248, 255);}

color* color_gold() { return color_rgb_int(255, 215, 0);}

color* color_goldenrod() { return color_rgb_int(218, 165, 32);}

color* color_gray() { return color_rgb_int(128, 128, 128);}

color* color_green() { return color_rgb_int(0, 128, 0);}

color* color_greenyellow() { return color_rgb_int(173, 255, 47);}

color* color_honeydew() { return color_rgb_int(240, 255, 240);}

color* color_hotpink() { return color_rgb_int(255, 105, 180);}

color* color_indianred() { return color_rgb_int(205, 92, 92);}

color* color_indigo() { return color_rgb_int(75, 0, 130);}

color* color_ivory() { return color_rgb_int(255, 255, 240);}

color* color_khaki() { return color_rgb_int(240, 230, 140);}

color* color_lavender() { return color_rgb_int(230, 230, 250);}

color* color_lavenderblush() { return color_rgb_int(255, 240, 245);}

color* color_lawngreen() { return color_rgb_int(124, 252, 0);}

color* color_lemonchiffon() { return color_rgb_int(255, 250, 205);}

color* color_lightblue() { return color_rgb_int(173, 216, 230);}

color* color_lightcoral() { return color_rgb_int(240, 128, 128);}

color* color_lightcyan() { return color_rgb_int(224, 255, 255);}

color* color_lightgoldenrodyellow() { return color_rgb_int(250, 250, 210);}

color* color_lightgray() { return color_rgb_int(211, 211, 211);}

color* color_lightgreen() { return color_rgb_int(144, 238, 144);}

color* color_lightgrey() { return color_rgb_int(211, 211, 211);}

color* color_lightpink() { return color_rgb_int(255, 182, 193);}

color* color_lightsalmon() { return color_rgb_int(255, 160, 122);}

color* color_lightseagreen() { return color_rgb_int(32, 178, 170);}

color* color_lightskyblue() { return color_rgb_int(135, 206, 250);}

color* color_lightslategray() { return color_rgb_int(119, 136, 153);}

color* color_lightslategrey() { return color_rgb_int(119, 136, 153);}

color* color_lightsteelblue() { return color_rgb_int(176, 196, 222);}

color* color_lightyellow() { return color_rgb_int(255, 255, 224);}

color* color_lime() { return color_rgb_int(0, 255, 0);}

color* color_limegreen() { return color_rgb_int(50, 205, 50);}

color* color_linen() { return color_rgb_int(250, 240, 230);}

color* color_magenta() { return color_rgb_int(255, 0, 255);}

color* color_maroon() { return color_rgb_int(128, 0, 0);}

color* color_mediumaquamarine() { return color_rgb_int(102, 205, 170);}

color* color_mediumblue() { return color_rgb_int(0, 0, 205);}

color* color_mediumorchid() { return color_rgb_int(186, 85, 211);}

color* color_mediumpurple() { return color_rgb_int(147, 112, 219);}

color* color_mediumseagreen() { return color_rgb_int(60, 179, 113);}

color* color_mediumslateblue() { return color_rgb_int(123, 104, 238);}

color* color_mediumspringgreen() { return color_rgb_int(0, 250, 154);}

color* color_mediumturquoise() { return color_rgb_int(72, 209, 204);}

color* color_mediumvioletred() { return color_rgb_int(199, 21, 133);}

color* color_midnightblue() { return color_rgb_int(25, 25, 112);}

color* color_mintcream() { return color_rgb_int(245, 255, 250);}

color* color_mistyrose() { return color_rgb_int(255, 228, 225);}

color* color_moccasin() { return color_rgb_int(255, 228, 181);}

color* color_navajowhite() { return color_rgb_int(255, 222, 173);}

color* color_navy() { return color_rgb_int(0, 0, 128);}

color* color_oldlace() { return color_rgb_int(253, 245, 230);}

color* color_olive() { return color_rgb_int(128, 128, 0);}

color* color_olivedrab() { return color_rgb_int(107, 142, 35);}

color* color_orange() { return color_rgb_int(255, 165, 0);}

color* color_orangered() { return color_rgb_int(255, 69, 0);}

color* color_orchid() { return color_rgb_int(218, 112, 214);}

color* color_palegoldenrod() { return color_rgb_int(238, 232, 170);}

color* color_palegreen() { return color_rgb_int(152, 251, 152);}

color* color_paleturquoise() { return color_rgb_int(175, 238, 238);}

color* color_palevioletred() { return color_rgb_int(219, 112, 147);}

color* color_papayawhip() { return color_rgb_int(255, 239, 213);}

color* color_peachpuff() { return color_rgb_int(255, 218, 185);}

color* color_peru() { return color_rgb_int(205, 133, 63);}

color* color_pink() { return color_rgb_int(255, 192, 203);}

color* color_plum() { return color_rgb_int(221, 160, 221);}

color* color_powderblue() { return color_rgb_int(176, 224, 230);}

color* color_purple() { return color_rgb_int(128, 0, 128);}

color* color_rebeccapurple() { return color_rgb_int(102, 51, 153);}

color* color_red() { return color_rgb_int(255, 0, 0);}

color* color_rosybrown() { return color_rgb_int(188, 143, 143);}

color* color_royalblue() { return color_rgb_int(65, 105, 225);}

color* color_saddlebrown() { return color_rgb_int(139, 69, 19);}

color* color_salmon() { return color_rgb_int(250, 128, 114);}

color* color_sandybrown() { return color_rgb_int(244, 164, 96);}

color* color_seagreen() { return color_rgb_int(46, 139, 87);}

color* color_seashell() { return color_rgb_int(255, 245, 238);}

color* color_sienna() { return color_rgb_int(160, 82, 45);}

color* color_silver() { return color_rgb_int(192, 192, 192);}

color* color_skyblue() { return color_rgb_int(135, 206, 235);}

color* color_slateblue() { return color_rgb_int(106, 90, 205);}

color* color_slategray() { return color_rgb_int(112, 128, 144);}

color* color_slategrey() { return color_rgb_int(112, 128, 144);}

color* color_snow() { return color_rgb_int(255, 250, 250);}

color* color_springgreen() { return color_rgb_int(0, 255, 127);}

color* color_steelblue() { return color_rgb_int(70, 130, 180);}

color* color_tan() { return color_rgb_int(210, 180, 140);}

color* color_teal() { return color_rgb_int(0, 128, 128);}

color* color_thistle() { return color_rgb_int(216, 191, 216);}

color* color_tomato() { return color_rgb_int(255, 99, 71);}

color* color_turquoise() { return color_rgb_int(64, 224, 208);}

color* color_violet() { return color_rgb_int(238, 130, 238);}

color* color_wheat() { return color_rgb_int(245, 222, 179);}

color* color_white() { return color_rgb_int(255, 255, 255);}

color* color_whitesmoke() { return color_rgb_int(245, 245, 245);}

color* color_yellow() { return color_rgb_int(255, 255, 0);}

color* color_yellowgreen() { return color_rgb_int(154, 205, 50);}
