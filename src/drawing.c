#include "drawing.h"
#include <cairo.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

void cairo_fill_text(cairo_t* cr, char* text, double x, double y) {
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_show_text(cr, text);
  cairo_fill(cr);
  cairo_restore(cr);
}

void cairo_printf(cairo_t* cr, double x, double y, char* fmt, ...) {
  va_list the_args;
  char text[1000];  // arbitrary size. should be ok for now?
  va_start(the_args, fmt);
  vsprintf(text, fmt, the_args);
  va_end(the_args);

  cairo_fill_text(cr, text, x, y);
}

void cairo_stroke_text(cairo_t* cr, char* text, double x, double y) {
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_show_text(cr, text);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_line(cairo_t* cr, double x0, double y0, double x1, double y1) {
  cairo_move_to(cr, x0, y0);
  cairo_line_to(cr, x1, y1);
  cairo_stroke(cr);
}

void cairo_line_through(cairo_t* cr, double x0, double y0, double x1, double y1, double overlap) {
  double dx = x1 - x0;
  double dy = y1 - y0;
  double dxy = dx * dx + dy * dy;
  double p2 = sqrt(dxy);

  cairo_save(cr);
  cairo_translate(cr, x0, y0);
  cairo_rotate(cr, atan2(dy, dx));
  cairo_move_to(cr, -overlap, 0);
  cairo_line_to(cr, p2 + overlap, 0);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_ray(cairo_t* cr, double x, double y, double angle, double offset, double length) {
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, angle);
  cairo_move_to(cr, offset, 0);
  cairo_line_to(cr, offset + length, 0);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_stroke_rectangle(cairo_t* cr, double x, double y, double w, double h) {
  cairo_rectangle(cr, x, y, w, h);
  cairo_stroke(cr);
}

void cairo_fill_rectangle(cairo_t* cr, double x, double y, double w, double h) {
  cairo_rectangle(cr, x, y, w, h);
  cairo_fill(cr);
}

void cairo_round_rectangle(cairo_t* cr, double x, double y, double w, double h, double r) {
  r = fmin(r, w / 2);
  r = fmin(r, h / 2);
  cairo_move_to(cr, x + r, y);
  cairo_line_to(cr, x + w - r, y);
  cairo_arc(cr, x + w - r, y + r, r, -PI_2, 0);
  cairo_line_to(cr, x + w, y + h - r);
  cairo_arc(cr, x + w - r, y + h - r, r, 0, PI_2);
  cairo_line_to(cr, x + r, y + h);
  cairo_arc(cr, x + r, y + h - r, r, PI_2, PI);
  cairo_line_to(cr, x, y + r);
  cairo_arc(cr, x + r, y + r, r, PI, -PI_2);
}
void cairo_stroke_round_rectangle(cairo_t* cr, double x, double y, double w, double h, double r) {
  cairo_round_rectangle(cr, x, y, w, h, r);
  cairo_stroke(cr);
}

void cairo_fill_round_rectangle(cairo_t* cr, double x, double y, double w, double h, double r) {
  cairo_round_rectangle(cr, x, y, w, h, r);
  cairo_fill(cr);
}

void cairo_circle(cairo_t* cr, double x, double y, double r) {
  cairo_arc(cr, x, y, r, 0, PI * 2);
}

void cairo_stroke_circle(cairo_t* cr, double x, double y, double r) {
  cairo_circle(cr, x, y, r);
  cairo_stroke(cr);
}

void cairo_fill_circle(cairo_t* cr, double x, double y, double r) {
  cairo_circle(cr, x, y, r);
  cairo_fill(cr);
}

void cairo_ellipse(cairo_t* cr, double x, double y, double xr, double yr) {
  if (xr <= 0 || yr <= 0) {
    return;
  }
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_scale(cr, xr, yr);
  cairo_circle(cr, 0, 0, 1);
  cairo_restore(cr);
}

void cairo_stroke_ellipse(cairo_t* cr, double x, double y, double xr, double yr) {
  cairo_ellipse(cr, x, y, xr, yr);
  cairo_stroke(cr);
}

void cairo_fill_ellipse(cairo_t* cr, double x, double y, double xr, double yr) {
  cairo_ellipse(cr, x, y, xr, yr);
  cairo_fill(cr);
}

void draw_path(cairo_t* cr, bl_point_list* list) {
  bl_point* curr = list->head;
  while (curr != NULL) {
    cairo_line_to(cr, curr->x, curr->y);
    curr = curr->next;
  }
}

void cairo_path(cairo_t* cr, bl_point_list* path) {
  draw_path(cr, path);
}

void cairo_stroke_path(cairo_t* cr, bl_point_list* path, bool close) {
  cairo_path(cr, path);
  if (close) {
    cairo_close_path(cr);
  }
  cairo_stroke(cr);
}

void cairo_fill_path(cairo_t* cr, bl_point_list* path) {
  cairo_path(cr, path);
  cairo_fill(cr);
}

void cairo_polygon(cairo_t* cr, double x, double y, double r, int sides, double rotation) {
  double angle;
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, rotation);
  cairo_move_to(cr, r, 0);
  for (int i = 0; i < sides; i++) {
    angle = PI * 2 / (double)sides * (double)i;
    cairo_line_to(cr, cos(angle) * r, sin(angle) * r);
  }
  cairo_line_to(cr, r, 0);
  cairo_restore(cr);
}

void cairo_stroke_polygon(cairo_t* cr, double x, double y, double r, int sides, double rotation) {
  cairo_polygon(cr, x, y, r, sides, rotation);
  cairo_stroke(cr);
}

void cairo_fill_polygon(cairo_t* cr, double x, double y, double r, int sides, double rotation) {
  cairo_polygon(cr, x, y, r, sides, rotation);
  cairo_fill(cr);
}

void cairo_star(cairo_t* cr, double x, double y, double r0, double r1, int points, double rotation) {
  double r;
  double angle;

  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, rotation);
  for (int i = 0; i < points * 2; i++) {
    r = r1;
    if (i % 2 == 1) {
      r = r0;
    }
    angle = PI / (double)points * (double)i;
    cairo_line_to(cr, cos(angle) * r, sin(angle) * r);
  }
  cairo_close_path(cr);
  cairo_restore(cr);
}

void cairo_stroke_star(cairo_t* cr, double x, double y, double r0, double r1, int points, double rotation) {
  cairo_star(cr, x, y, r0, r1, points, rotation);
  cairo_stroke(cr);
}

void cairo_fill_star(cairo_t* cr, double x, double y, double r0, double r1, int points, double rotation) {
  cairo_star(cr, x, y, r0, r1, points, rotation);
  cairo_fill(cr);
}

void cairo_stroke_curve_to(cairo_t* cr, double x0, double y0, double x1, double y1, double x2, double y2) {
  cairo_curve_to(cr, x0, y0, x1, y1, x2, y2);
  cairo_stroke(cr);
}

void cairo_quad_curve_to(cairo_t* cr, double x0, double y0, double x1, double y1) {
  double px;
  double py;

  cairo_get_current_point(cr, &px, &py);
  cairo_curve_to(cr, 2.0 / 3.0 * x0 + 1.0 / 3.0 * px, 2.0 / 3.0 * y0 + 1.0 / 3.0 * py, 2.0 / 3.0 * x0 + 1.0 / 3.0 * x1,
                 2.0 / 3.0 * y0 + 1.0 / 3.0 * y1, x1, y1);
}
void cairo_plot(cairo_t* cr, double x, double y) {
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_fill_rectangle(cr, -0.5, -0.5, 1, 1);
  cairo_restore(cr);
}

void cairo_stroke_quad_curve_to(cairo_t* cr, double x0, double y0, double x1, double y1) {
  cairo_quad_curve_to(cr, x0, y0, x1, y1);
  cairo_stroke(cr);
}

bl_point* splat_point(double angle, double radius) {
  return bl_make_point(cos(angle) * radius, sin(angle) * radius);
}

void cairo_splat(cairo_t* cr, double x, double y, int num_nodes, double radius, double inner_radius, double variation) {
  bl_point_list* path = bl_make_point_list();
  double slice = PI * 2 / (double)(num_nodes * 2);
  double angle = 0.0;
  double curve = 0.3;
  double radius_range = radius - inner_radius;

  variation = bl_clamp(variation, 0, 1);
  for (int i = 0; i < num_nodes; i++) {
    double r = radius + variation * rand_double_range(-radius_range, radius_range);
    double rr = r - inner_radius;
    bl_add_point(path, splat_point(angle - slice * (1.0 + curve), inner_radius));
    bl_add_point(path, splat_point(angle + slice * curve, inner_radius));
    bl_add_point(path, splat_point(angle - slice * curve, inner_radius + rr * 0.8));
    bl_add_point(path, splat_point(angle + slice / 2.0, r));
    bl_add_point(path, splat_point(angle + slice * (1.0 + curve), inner_radius + rr * 0.8));
    angle += slice * 2.0;
  }
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_multi_loop(cr, path);
  cairo_restore(cr);
  bl_point_list_destroy(path);
}

void cairo_stroke_splat(cairo_t* cr,
                        double x,
                        double y,
                        int num_nodes,
                        double radius,
                        double inner_radius,
                        double variation) {
  cairo_splat(cr, x, y, num_nodes, radius, inner_radius, variation);
  cairo_stroke(cr);
}

void cairo_fill_splat(cairo_t* cr,
                      double x,
                      double y,
                      int num_nodes,
                      double radius,
                      double inner_radius,
                      double variation) {
  cairo_splat(cr, x, y, num_nodes, radius, inner_radius, variation);
  cairo_fill(cr);
}

void cairo_multi_loop(cairo_t* cr, bl_point_list* path) {
  int count = bl_point_list_count(path);

  bl_point points[count];
  bl_point* curr = path->head;
  int index = 0;
  while (curr != NULL) {
    points[index] = *curr;
    curr = curr->next;
    index++;
  }
  bl_point pa = points[0];
  bl_point pz = points[count - 1];
  double mid1x = (pz.x + pa.x) / 2.0;
  double mid1y = (pz.y + pa.y) / 2.0;
  cairo_move_to(cr, mid1x, mid1y);
  for (int i = 0; i < count - 1; i++) {
    bl_point p0 = points[i];
    bl_point p1 = points[i + 1];
    double midx = (p0.x + p1.x) / 2.0;
    double midy = (p0.y + p1.y) / 2.0;
    cairo_quad_curve_to(cr, p0.x, p0.y, midx, midy);
  }
  cairo_quad_curve_to(cr, pz.x, pz.y, mid1x, mid1y);
}

void cairo_stroke_multi_loop(cairo_t* cr, bl_point_list* path) {
  cairo_multi_loop(cr, path);
  cairo_stroke(cr);
}

void cairo_fill_multi_loop(cairo_t* cr, bl_point_list* path) {
  cairo_multi_loop(cr, path);
  cairo_fill(cr);
}

void cairo_multi_curve(cairo_t* cr, bl_point_list* path) {
  int count = bl_point_list_count(path);

  bl_point points[count];
  bl_point* curr = path->head;
  int index = 0;
  while (curr != NULL) {
    points[index] = *curr;
    curr = curr->next;
    index++;
  }

  bl_point p0 = points[0];
  bl_point p1 = points[1];
  cairo_move_to(cr, p0.x, p0.y);
  cairo_line_to(cr, (p0.x + p1.x) / 2, (p0.y + p1.y) / 2);
  for (int i = 1; i < count - 1; i++) {
    bl_point p0 = points[i];
    bl_point p1 = points[i + 1];
    double midx = (p0.x + p1.x) / 2;
    double midy = (p0.y + p1.y) / 2;
    cairo_quad_curve_to(cr, p0.x, p0.y, midx, midy);
  }
  bl_point p = points[count - 1];
  cairo_line_to(cr, p.x, p.y);
}

void cairo_stroke_multi_curve(cairo_t* cr, bl_point_list* path) {
  cairo_multi_curve(cr, path);
  cairo_stroke(cr);
}

void cairo_fill_multi_curve(cairo_t* cr, bl_point_list* path) {
  cairo_multi_curve(cr, path);
  cairo_fill(cr);
}

void cairo_draw_points(cairo_t* cr, bl_point_list* path, double radius) {
  bl_point* curr = path->head;
  while (curr != NULL) {
    cairo_fill_circle(cr, curr->x, curr->y, radius);
    curr = curr->next;
  }
}

void cairo_fractal_line(cairo_t* cr, double x0, double y0, double x1, double y1, double roughness, int iterations) {
  double dx = x1 - x0;
  double dy = y1 - y0;
  double offset = sqrt(dx * dx + dy * dy) * 0.15;

  bl_point_list* path = bl_make_point_list();
  bl_add_point_xy(path, x0, y0);
  bl_add_point_xy(path, x1, y1);

  for (int i = 0; i < iterations; i++) {
    bl_point* curr = path->head;
    while (curr->next != NULL) {
      bl_point* next = curr->next;
      double x = (curr->x + next->x) / 2.0 + rand_double_range(-offset, offset);
      double y = (curr->y + next->y) / 2.0 + rand_double_range(-offset, offset);
      bl_point* middle = bl_make_point(x, y);
      middle->next = next;
      curr->next = middle;
      curr = next;
    }
    offset *= roughness;
  }
  cairo_path(cr, path);
  bl_point_list_destroy(path);
}

void cairo_stroke_fractal_line(cairo_t* cr,
                               double x0,
                               double y0,
                               double x1,
                               double y1,
                               double roughness,
                               int iterations) {
  cairo_fractal_line(cr, x0, y0, x1, y1, roughness, iterations);
  cairo_stroke(cr);
}

void cairo_heart(cairo_t* cr, double x, double y, double w, double h, double r) {
  double res = sqrt(w * h);
  bl_point_list* path = bl_make_point_list();

  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, r);
  for (int i = 0; i < res; i++) {
    double a = PI * 2 * (double)i / res;
    double x = w * pow(sin(a), 3.0);
    double y = h * (0.8125 * cos(a) - 0.3125 * cos(2.0 * a) - 0.125 * cos(3.0 * a) - 0.0625 * cos(4.0 * a));
    bl_add_point_xy(path, x, -y);
  }
  cairo_path(cr, path);
  cairo_restore(cr);
  bl_point_list_destroy(path);
}
void cairo_stroke_heart(cairo_t* cr, double x, double y, double w, double h, double r) {
  cairo_heart(cr, x, y, w, h, r);
  cairo_stroke(cr);
}

void cairo_fill_heart(cairo_t* cr, double x, double y, double w, double h, double r) {
  cairo_heart(cr, x, y, w, h, r);
  cairo_fill(cr);
}

void cairo_grid(cairo_t* cr, double x, double y, double w, double h, double xres, double yres) {
  for (double i = x; i < x + w; i += xres) {
    cairo_move_to(cr, i, y);
    cairo_line_to(cr, i, y + h);
  }
  for (double i = y; i < y + h; i += yres) {
    cairo_move_to(cr, x, i);
    cairo_line_to(cr, x + w, i);
  }
  cairo_stroke(cr);
}

void cairo_hex_grid(cairo_t* cr, double x, double y, double w, double h, double res_0, double res_1) {
  double sin_60_r = sin(PI / 3) * res_0;
  double x_inc = 2 * sin_60_r;
  double y_inc = res_0 * 1.5;
  double offset = 0;

  for (double yy = y; yy < y + h + y_inc; yy += y_inc) {
    for (double xx = x; xx < x + w + x_inc; xx += x_inc) {
      cairo_polygon(cr, xx + offset, yy, res_1, 6, PI / 2);
    }
    if (offset == 0) {
      offset = sin_60_r;
    } else {
      offset = 0;
    }
  }
}
void cairo_fill_hex_grid(cairo_t* cr, double x, double y, double w, double h, double res_0, double res_1) {
  cairo_save(cr);
  cairo_rectangle(cr, x, y, w, h);
  cairo_clip(cr);
  cairo_hex_grid(cr, x, y, w, h, res_0, res_1);
  cairo_fill(cr);
  cairo_restore(cr);
}
void cairo_stroke_hex_grid(cairo_t* cr, double x, double y, double w, double h, double res_0, double res_1) {
  cairo_save(cr);
  cairo_rectangle(cr, x, y, w, h);
  cairo_clip(cr);
  cairo_hex_grid(cr, x, y, w, h, res_0, res_1);
  cairo_stroke(cr);
  cairo_restore(cr);
}
