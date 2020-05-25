#ifndef _CAIRO_COLORS_H_
#define _CAIRO_COLORS_H_

#include "color.h"
#include <cairo.h>

/**
 * Sets the drawing source color using an instance of `bl_color`.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_color *c The color to use.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_hsv(90, 1, 0.5);
 *     cairo_set_source_color(cr, c);
 *     free(c);
 */
void cairo_set_source_color(cairo_t *cr, bl_color *c);

/**
 * Sets the drawing source color to a shade of grey.
 *
 * @param cairo_t *cr The cairo context.
 * @param double g A value from 0 to 1 representing a shade of grey.
 *
 * **Examples**
 *
 *     cairo_set_source_grey(cr, 0.5);
 */
void cairo_set_source_grey(cairo_t *cr, double g);

/**
 * Sets the drawing source color to white.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_set_source_white(cr);
 */
void cairo_set_source_white(cairo_t *cr);

/**
 * Sets the drawing source color to black.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_set_source_black(cr);
 */
void cairo_set_source_black(cairo_t *cr);

/**
 * Sets the drawing source color using hue, saturation and value.
 *
 * @param cairo_t *cr The cairo context.
 * @param double h The hue.
 * @param double s The saturation.
 * @param double v The value.
 *
 * **Examples**
 *
 *     cairo_set_source_hsv(90, 1, 0.5);
 */
void cairo_set_source_hsv(cairo_t *cr, double h, double s, double v);

/**
 * Sets the drawing source color to a random rgb value.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_set_source_random_rgb(cr);
 */
void cairo_set_source_random_rgb(cairo_t *cr);

/**
 * Sets the drawing source color to a random shade of grey.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_set_source_random_grey(cr);
 */
void cairo_set_source_random_grey(cairo_t *cr);

/**
 * Clears the cairo context to an rgba color value.
 *
 * @param cairo_t *cr The cairo context.
 * @param double r The red value.
 * @param double g The green value.
 * @param double b The blue value.
 * @param double a The alpha value.
 *
 * **Examples**
 *
 *     cairo_clear_rgba(cr, 1, 1, 1, 0.5);
 */
void cairo_clear_rgba(cairo_t *cr, double r, double g, double b, double a);

/**
 * Clears the cairo context to an rgb color value.
 *
 * @param cairo_t *cr The cairo context.
 * @param double r The red value.
 * @param double g The green value.
 * @param double b The blue value.
 *
 * **Examples**
 *
 *     cairo_clear_rgb(cr, 1, 1, 1);
 */
void cairo_clear_rgb(cairo_t *cr, double r, double g, double b);

/**
 * Clears the cairo context to a color specified by an instance of `bl_color`.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_color *c The color to use.
 *
 * **Examples**
 *
 *     bl_color *c = bl_color_hsv(90, 1, 0.5);
 *     cairo_clear_color(cr, c);
 *     free(c);
 */
void cairo_clear_color(cairo_t *cr, bl_color *c);

/**
 * Clears the cairo context to a shade of grey.
 *
 * @param cairo_t *cr The cairo context.
 * @param double g A value from 0 to 1 representing a shade of grey.
 *
 * **Examples**
 *
 *     cairo_clear_grey(cr, 0.5);
 */
void cairo_clear_grey(cairo_t *cr, double g);

/**
 * Clears the cairo context to white.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_clear_white(cr);
 */
void cairo_clear_white(cairo_t *cr);

/**
 * Clears the cairo context to black.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_clear_black(cr);
 */
void cairo_clear_black(cairo_t *cr);

/**
 * Clears the cairo context to color specified with hue, saturation and value.
 *
 * @param cairo_t *cr The cairo context.
 * @param double h The hue.
 * @param double s The saturation.
 * @param double v The value.
 *
 * **Examples**
 *
 *     cairo_clear_hsv(cr, 90, 1, 0.5);
 */
void cairo_clear_hsv(cairo_t *cr, double h, double s, double v);

/**
 * Clears the cairo context to a random rgb color.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_clear_random_rgb(cr);
 */
void cairo_clear_random_rgb(cairo_t *cr);

/**
 * Clears the cairo context to a random shade of grey.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     cairo_clear_random_grey(cr);
 */
void cairo_clear_random_grey(cairo_t *cr);
#endif
