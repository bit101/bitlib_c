#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color
{
  double r;
  double g;
  double b;
  double a;
} color;

color* color_rgba(double r, double g, double b, double a);

color* color_rgb(double r, double g, double b);

color* color_rgba_hex(int r, int g, int b, int a);

color* color_rgb_hex(int r, int g, int b);

color* color_number(int value);

color* color_number_with_alpha(int value);

color* color_lerp(color *color_a, color *color_b, double t);

color* color_random_rgb();

color* color_hsv(double h, double s, double v);

color* color_grey(double shade);

color* color_grey_hex(int shade);

color* color_random_grey();

color* color_random_grey_range(double min, double max);



color* color_blueviolet();

color* color_brown();

color* color_aliceblue();

color* color_antiquewhite();

color* color_aqua();

color* color_aquamarine();

color* color_azure();

color* color_beige();

color* color_bisque();

color* color_black();

color* color_blanchedalmond();

color* color_blue();

color* color_burlywood();

color* color_cadetblue();

color* color_chartreuse();

color* color_chocolate();

color* color_coral();

color* color_cornflowerblue();

color* color_cornsilk();

color* color_crimson();

color* color_cyan();

color* color_darkblue();

color* color_darkcyan();

color* color_darkgoldenrod();

color* color_darkgray();

color* color_darkgreen();

color* color_darkgrey();

color* color_darkkhaki();

color* color_darkmagenta();

color* color_darkolivegreen();

color* color_darkorange();

color* color_darkorchid();

color* color_darkred();

color* color_darksalmon();

color* color_darkseagreen();

color* color_darkslateblue();

color* color_darkslategray();

color* color_darkslategrey();

color* color_darkturquoise();

color* color_darkviolet();

color* color_deeppink();

color* color_deepskyblue();

color* color_dimgray();

color* color_dimgrey();

color* color_dodgerblue();

color* color_firebrick();

color* color_floralwhite();

color* color_forestgreen();

color* color_fuchsia();

color* color_gainsboro();

color* color_ghostwhite();

color* color_gold();

color* color_goldenrod();

color* color_gray();

color* color_green();

color* color_greenyellow();

color* color_honeydew();

color* color_hotpink();

color* color_indianred();

color* color_indigo();

color* color_ivory();

color* color_khaki();

color* color_lavender();

color* color_lavenderblush();

color* color_lawngreen();

color* color_lemonchiffon();

color* color_lightblue();

color* color_lightcoral();

color* color_lightcyan();

color* color_lightgoldenrodyellow();

color* color_lightgray();

color* color_lightgreen();

color* color_lightgrey();

color* color_lightpink();

color* color_lightsalmon();

color* color_lightseagreen();

color* color_lightskyblue();

color* color_lightslategray();

color* color_lightslategrey();

color* color_lightsteelblue();

color* color_lightyellow();

color* color_lime();

color* color_limegreen();

color* color_linen();

color* color_magenta();

color* color_maroon();

color* color_mediumaquamarine();

color* color_mediumblue();

color* color_mediumorchid();

color* color_mediumpurple();

color* color_mediumseagreen();

color* color_mediumslateblue();

color* color_mediumspringgreen();

color* color_mediumturquoise();

color* color_mediumvioletred();

color* color_midnightblue();

color* color_mintcream();

color* color_mistyrose();

color* color_moccasin();

color* color_navajowhite();

color* color_navy();

color* color_oldlace();

color* color_olive();

color* color_olivedrab();

color* color_orange();

color* color_orangered();

color* color_orchid();

color* color_palegoldenrod();

color* color_palegreen();

color* color_paleturquoise();

color* color_palevioletred();

color* color_papayawhip();

color* color_peachpuff();

color* color_peru();

color* color_pink();

color* color_plum();

color* color_powderblue();

color* color_purple();

color* color_rebeccapurple();

color* color_red();

color* color_rosybrown();

color* color_royalblue();

color* color_saddlebrown();

color* color_salmon();

color* color_sandybrown();

color* color_seagreen();

color* color_seashell();

color* color_sienna();

color* color_silver();

color* color_skyblue();

color* color_slateblue();

color* color_slategray();

color* color_slategrey();

color* color_snow();

color* color_springgreen();

color* color_steelblue();

color* color_tan();

color* color_teal();

color* color_thistle();

color* color_tomato();

color* color_turquoise();

color* color_violet();

color* color_wheat();

color* color_white();

color* color_whitesmoke();

color* color_yellow();

color* color_yellowgreen();

#endif
