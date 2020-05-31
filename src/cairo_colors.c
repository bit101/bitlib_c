#include <cairo.h>
#include <stdlib.h>
#include "bitlib.h"

////////////////////
// SET SOURCE
////////////////////
void cairo_set_source_color(cairo_t* cr, bl_color* c) {
  cairo_set_source_rgba(cr, c->r, c->g, c->b, c->a);
}

void cairo_set_source_grey(cairo_t* cr, double g) {
  cairo_set_source_rgb(cr, g, g, g);
}

void cairo_set_source_white(cairo_t* cr) {
  cairo_set_source_rgb(cr, 1, 1, 1);
}

void cairo_set_source_black(cairo_t* cr) {
  cairo_set_source_rgb(cr, 0, 0, 0);
}

void cairo_set_source_hsv(cairo_t* cr, double h, double s, double v) {
  bl_color* col = bl_color_hsv(h, s, v);
  cairo_set_source_color(cr, col);
  free(col);
}

void cairo_set_source_random_rgb(cairo_t* cr) {
  bl_color* col = bl_color_random_rgb();
  cairo_set_source_color(cr, col);
  free(col);
}

void cairo_set_source_random_grey(cairo_t* cr) {
  bl_color* col = bl_color_random_grey();
  cairo_set_source_color(cr, col);
  free(col);
}

////////////////////
// CLEAR
////////////////////

void cairo_clear_rgba(cairo_t* cr, double r, double g, double b, double a) {
  cairo_save(cr);
  cairo_set_source_rgba(cr, r, g, b, a);
  cairo_paint(cr);
  cairo_restore(cr);
}

void cairo_clear_rgb(cairo_t* cr, double r, double g, double b) {
  cairo_clear_rgba(cr, r, g, b, 1.0);
}

void cairo_clear_color(cairo_t* cr, bl_color* c) {
  cairo_clear_rgb(cr, c->r, c->g, c->b);
}
void cairo_clear_grey(cairo_t* cr, double g) {
  cairo_clear_rgba(cr, g, g, g, 1.0);
}

void cairo_clear_white(cairo_t* cr) {
  cairo_clear_rgba(cr, 1, 1, 1, 1.0);
}

void cairo_clear_black(cairo_t* cr) {
  cairo_clear_rgba(cr, 0, 0, 0, 1.0);
}

void cairo_clear_hsv(cairo_t* cr, double h, double s, double v) {
  bl_color* col = bl_color_hsv(h, s, v);
  cairo_clear_color(cr, col);
  free(col);
}

void cairo_clear_random_rgb(cairo_t* cr) {
  bl_color* col = bl_color_random_rgb();
  cairo_clear_color(cr, col);
  free(col);
}

void cairo_clear_random_grey(cairo_t* cr) {
  bl_color* col = bl_color_random_grey();
  cairo_clear_color(cr, col);
  free(col);
}
