#ifndef _CAIRO_COLORS_H_
#define _CAIRO_COLORS_H_

#include "color.h"
#include <cairo.h>

void cairo_set_source_color(cairo_t *cr, bl_color *c);
void cairo_set_source_grey(cairo_t *cr, double g);
void cairo_set_source_white(cairo_t *cr);
void cairo_set_source_black(cairo_t *cr);
void cairo_set_source_hsv(cairo_t *cr, double h, double s, double v);
void cairo_set_source_random_rgb(cairo_t *cr);
void cairo_set_source_random_grey(cairo_t *cr);

void cairo_clear_rgba(cairo_t *cr, double r, double g, double b, double a);
void cairo_clear_rgb(cairo_t *cr, double r, double g, double b);
void cairo_clear_color(cairo_t *cr, bl_color *c);
void cairo_clear_grey(cairo_t *cr, double g);
void cairo_clear_white(cairo_t *cr);
void cairo_clear_black(cairo_t *cr);
void cairo_clear_hsv(cairo_t *cr, double h, double s, double v);
void cairo_clear_random_rgb(cairo_t *cr);
void cairo_clear_random_grey(cairo_t *cr);
#endif
