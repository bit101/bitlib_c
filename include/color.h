#ifndef _COLOR_H_
#define _COLOR_H_

/**
 * A struct for holding an rgba color value.
 */
typedef struct Color {
  double r;
  double g;
  double b;
  double a;
} bl_color;

/**
 * Returns an instance of `bl_color` using red, green, blue and alpha values.
 *
 * Values for each channel will be from 0 to 1.
 *
 * @param double r The red value.
 * @param double g The green value.
 * @param double b The blue value.
 * @param double a The alpha value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_rgba(1, 0, 0.5, 1)
 */
bl_color* bl_color_rgba(double r, double g, double b, double a);

/**
 * Returns an instance of `bl_color` using red, green and blue values.
 *
 * Values for each channel will be from 0 to 1.
 *
 * @param double r The red value.
 * @param double g The green value.
 * @param double b The blue value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_rgb(1, 0, 0.5)
 */
bl_color* bl_color_rgb(double r, double g, double b);

/**
 * Returns an instance of `bl_color` using integer values for red, green, blue
 * and alpha.
 *
 * Values for each channel will be integers from 0 to 255.
 *
 * @param int r The red value.
 * @param int g The green value.
 * @param int b The blue value.
 * @param int a The alpha value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_rgba_int(255, 20, 25, 255)
 */
bl_color* bl_color_rgba_int(int r, int g, int b, int a);

/**
 * Returns an instance of `bl_color` using integer values for red, green and
 * blue.
 *
 * Values for each channel will be integers from 0 to 255.
 *
 * @param int r The red value.
 * @param int g The green value.
 * @param int b The blue value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_rgb_int(255, 20, 25)
 */
bl_color* bl_color_rgb_int(int r, int g, int b);

/**
 * Returns an instance of `bl_color` using a 24-bit integer.
 *
 * While the integer input can be in any form, it is often expressed in
 * hexadecimal, for example: `0xffcc00`, where the pairs of values are
 * represented as `0xRRGGBB` (red, green, blue).
 *
 * @param int value The color value expressed in a single 24-bit integer.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_int_24(0xffcc00)
 */
bl_color* bl_color_int_24(int value);

/**
 * Returns an instance of `bl_color` using a 32-bit integer.
 *
 * While the integer input can be in any form, it is often expressed in
 * hexadecimal, for example: `0xffffcc00`, where the pairs of values are
 * represented as `0xAARRGGBB` (alpha, red, green, blue).
 *
 * @param int value The color value expressed in a single 24-bit integer.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_int_24(0x80ffcc00)
 */
bl_color* bl_color_int_32(int value);

/**
 * Interpolates between to instances of `bl_color`, returning a new instance.
 *
 * If the interpolation value is 0, it will return the first color. If it is 1,
 * it will return the second color. If it is between 0 and 1, it will blend the
 * two colors by interpolating between the two colors' red, gree, blue and alpha
 * channels.
 *
 * @param bl_color *color_a The first color.
 * @param bl_color *color_b The second color.
 * @param double t The interpolation value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *      bl_color *a = bl_color_rgb(1, 0, 0.5);
 *      bl_color *b = bl_color_rgb(0.3, 0.9, 1);
 *      bl_color *c = bl_color_lerp(a, b, 0.7);
 *      free(a);
 *      free(b);
 *
 */
bl_color* bl_color_lerp(bl_color* color_a, bl_color* color_b, double t);

/**
 * Returns an instance of `bl_color` with random red, green and blue channels.
 * The alpha channel will be set to 1.
 *
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_random_rgb();
 */
bl_color* bl_color_random_rgb();

/**
 * Returns an instance of `bl_color` using hue, saturation and value.
 *
 * @param double h The hue.
 * @param double s The saturation.
 * @param double v The value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_hsv(90, 1, 0.5);
 */
bl_color* bl_color_hsv(double h, double s, double v);

/**
 * Returns an instance of `bl_color` with a specified shade of grey.
 *
 * The `shade` parameter should be between 0 and 1.
 *
 * @param double shade The shade of grey.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_grey(0.75);
 */
bl_color* bl_color_grey(double shade);

/**
 * Returns an instance of `bl_color` with a specified shade of grey.
 *
 * The `shade` paramater should be an integer from 0 to 255.
 *
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_grey(200);
 */
bl_color* bl_color_grey_int(int shade);

/**
 * Returns an instnce of `bl_color` with a random shade of grey.
 *
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_random_grey();
 */
bl_color* bl_color_random_grey();

/**
 * Returns an instnce of `bl_color` with a random shade of grey within a certain
 * range.
 *
 * @param double min The minimum grey value.
 * @param double max The maximum grey value.
 * @returns bl_color*.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_random_grey_range(0, 0.5);
 */
bl_color* bl_color_random_grey_range(double min, double max);

/**
 * Creates a blueviolet color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_blueviolet();

/**
 * Creates a brown color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_brown();

/**
 * Creates a aliceblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_aliceblue();

/**
 * Creates a antiquewhite color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_antiquewhite();

/**
 * Creates a aqua color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_aqua();

/**
 * Creates a aquamarine color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_aquamarine();

/**
 * Creates a azure color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_azure();

/**
 * Creates a beige color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_beige();

/**
 * Creates a bisque color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_bisque();

/**
 * Creates a black color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_black();

/**
 * Creates a blanchedalmond color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_blanchedalmond();

/**
 * Creates a blue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_blue();

/**
 * Creates a burlywood color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_burlywood();

/**
 * Creates a cadetblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_cadetblue();

/**
 * Creates a chartreuse color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_chartreuse();

/**
 * Creates a chocolate color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_chocolate();

/**
 * Creates a coral color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_coral();

/**
 * Creates a cornflowerblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_cornflowerblue();

/**
 * Creates a cornsilk color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_cornsilk();

/**
 * Creates a crimson color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_crimson();

/**
 * Creates a cyan color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_cyan();

/**
 * Creates a darkblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkblue();

/**
 * Creates a darkcyan color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkcyan();

/**
 * Creates a darkgoldenrod color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkgoldenrod();

/**
 * Creates a darkgray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkgray();

/**
 * Creates a darkgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkgreen();

/**
 * Creates a darkgrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkgrey();

/**
 * Creates a darkkhaki color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkkhaki();

/**
 * Creates a darkmagenta color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkmagenta();

/**
 * Creates a darkolivegreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkolivegreen();

/**
 * Creates a darkorange color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkorange();

/**
 * Creates a darkorchid color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkorchid();

/**
 * Creates a darkred color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkred();

/**
 * Creates a darksalmon color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darksalmon();

/**
 * Creates a darkseagreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkseagreen();

/**
 * Creates a darkslateblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkslateblue();

/**
 * Creates a darkslategray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkslategray();

/**
 * Creates a darkslategrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkslategrey();

/**
 * Creates a darkturquoise color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkturquoise();

/**
 * Creates a darkviolet color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_darkviolet();

/**
 * Creates a deeppink color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_deeppink();

/**
 * Creates a deepskyblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_deepskyblue();

/**
 * Creates a dimgray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_dimgray();

/**
 * Creates a dimgrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_dimgrey();

/**
 * Creates a dodgerblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_dodgerblue();

/**
 * Creates a firebrick color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_firebrick();

/**
 * Creates a floralwhite color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_floralwhite();

/**
 * Creates a forestgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_forestgreen();

/**
 * Creates a fuchsia color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_fuchsia();

/**
 * Creates a gainsboro color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_gainsboro();

/**
 * Creates a ghostwhite color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_ghostwhite();

/**
 * Creates a gold color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_gold();

/**
 * Creates a goldenrod color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_goldenrod();

/**
 * Creates a gray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_gray();

/**
 * Creates a green color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_green();

/**
 * Creates a greenyellow color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_greenyellow();

/**
 * Creates a honeydew color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_honeydew();

/**
 * Creates a hotpink color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_hotpink();

/**
 * Creates a indianred color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_indianred();

/**
 * Creates a indigo color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_indigo();

/**
 * Creates a ivory color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_ivory();

/**
 * Creates a khaki color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_khaki();

/**
 * Creates a lavender color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lavender();

/**
 * Creates a lavenderblush color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lavenderblush();

/**
 * Creates a lawngreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lawngreen();

/**
 * Creates a lemonchiffon color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lemonchiffon();

/**
 * Creates a lightblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightblue();

/**
 * Creates a lightcoral color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightcoral();

/**
 * Creates a lightcyan color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightcyan();

/**
 * Creates a lightgoldenrodyellow color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightgoldenrodyellow();

/**
 * Creates a lightgray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightgray();

/**
 * Creates a lightgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightgreen();

/**
 * Creates a lightgrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightgrey();

/**
 * Creates a lightpink color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightpink();

/**
 * Creates a lightsalmon color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightsalmon();

/**
 * Creates a lightseagreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightseagreen();

/**
 * Creates a lightskyblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightskyblue();

/**
 * Creates a lightslategray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightslategray();

/**
 * Creates a lightslategrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightslategrey();

/**
 * Creates a lightsteelblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightsteelblue();

/**
 * Creates a lightyellow color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lightyellow();

/**
 * Creates a lime color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_lime();

/**
 * Creates a limegreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_limegreen();

/**
 * Creates a linen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_linen();

/**
 * Creates a magenta color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_magenta();

/**
 * Creates a maroon color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_maroon();

/**
 * Creates a mediumaquamarine color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumaquamarine();

/**
 * Creates a mediumblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumblue();

/**
 * Creates a mediumorchid color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumorchid();

/**
 * Creates a mediumpurple color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumpurple();

/**
 * Creates a mediumseagreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumseagreen();

/**
 * Creates a mediumslateblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumslateblue();

/**
 * Creates a mediumspringgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumspringgreen();

/**
 * Creates a mediumturquoise color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumturquoise();

/**
 * Creates a mediumvioletred color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mediumvioletred();

/**
 * Creates a midnightblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_midnightblue();

/**
 * Creates a mintcream color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mintcream();

/**
 * Creates a mistyrose color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_mistyrose();

/**
 * Creates a moccasin color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_moccasin();

/**
 * Creates a navajowhite color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_navajowhite();

/**
 * Creates a navy color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_navy();

/**
 * Creates a oldlace color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_oldlace();

/**
 * Creates a olive color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_olive();

/**
 * Creates a olivedrab color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_olivedrab();

/**
 * Creates a orange color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_orange();

/**
 * Creates a orangered color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_orangered();

/**
 * Creates a orchid color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_orchid();

/**
 * Creates a palegoldenrod color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_palegoldenrod();

/**
 * Creates a palegreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_palegreen();

/**
 * Creates a paleturquoise color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_paleturquoise();

/**
 * Creates a palevioletred color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_palevioletred();

/**
 * Creates a papayawhip color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_papayawhip();

/**
 * Creates a peachpuff color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_peachpuff();

/**
 * Creates a peru color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_peru();

/**
 * Creates a pink color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_pink();

/**
 * Creates a plum color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_plum();

/**
 * Creates a powderblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_powderblue();

/**
 * Creates a purple color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_purple();

/**
 * Creates a rebeccapurple color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_rebeccapurple();

/**
 * Creates a red color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_red();

/**
 * Creates a rosybrown color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_rosybrown();

/**
 * Creates a royalblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_royalblue();

/**
 * Creates a saddlebrown color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_saddlebrown();

/**
 * Creates a salmon color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_salmon();

/**
 * Creates a sandybrown color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_sandybrown();

/**
 * Creates a seagreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_seagreen();

/**
 * Creates a seashell color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_seashell();

/**
 * Creates a sienna color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_sienna();

/**
 * Creates a silver color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_silver();

/**
 * Creates a skyblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_skyblue();

/**
 * Creates a slateblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_slateblue();

/**
 * Creates a slategray color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_slategray();

/**
 * Creates a slategrey color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_slategrey();

/**
 * Creates a snow color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_snow();

/**
 * Creates a springgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_springgreen();

/**
 * Creates a steelblue color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_steelblue();

/**
 * Creates a tan color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_tan();

/**
 * Creates a teal color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_teal();

/**
 * Creates a thistle color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_thistle();

/**
 * Creates a tomato color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_tomato();

/**
 * Creates a turquoise color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_turquoise();

/**
 * Creates a violet color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_violet();

/**
 * Creates a wheat color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_wheat();

/**
 * Creates a white color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_white();

/**
 * Creates a whitesmoke color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_whitesmoke();

/**
 * Creates a yellow color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_yellow();

/**
 * Creates a yellowgreen color.
 *
 * @returns bl_color*.
 */
bl_color* bl_color_yellowgreen();

#endif
