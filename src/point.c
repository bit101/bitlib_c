#include <math.h>
#include <malloc.h>
#include <gtk/gtk.h>
#include "point.h"
#include "blmath.h"

bl_point* bl_make_point(double x, double y) {
  bl_point *p = (bl_point*)malloc(sizeof(bl_point));
  p->x = x;
  p->y = y;
  p->next = NULL;
  return p;
}

bl_point_list* bl_make_point_list() {
  bl_point_list *p = (bl_point_list*)malloc(sizeof(bl_point_list));
  p->head = NULL;
  return p;
}

void bl_add_point_xy(bl_point_list *list, double x, double y) {
  bl_add_point(list, bl_make_point(x, y));
}

void bl_add_point(bl_point_list *list, bl_point *p) {
  bl_point *curr = list->head;
  bl_point *next = p;
  if (curr == NULL) {
    list->head = next;
  } else {
    while(curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = next;
  }
}

bl_point* bl_lerp_point(double t, bl_point *p0, bl_point *p1) {
  double x = bl_lerp(t, p0->x, p1->x);
  double y = bl_lerp(t, p0->y, p1->y);
  return bl_make_point(x, y);
}

bl_point* bl_random_point(double x, double y, double w, double h) {
  double px = g_random_double_range(x, x + w);
  double py = g_random_double_range(y, y + h);
  return bl_make_point(px, py);
}

bl_point* bl_random_point_in_circle(double x, double y, double r) {
  double angle = g_random_double_range(0, G_PI * 2);
  double radius = g_random_double_range(0, r);
  return bl_make_point(x + cos(angle) * radius, y + sin(angle) * radius);
}

bl_point* bl_point_from_polar(double angle, double radius) {
  return bl_make_point(cos(angle) * radius, sin(angle)* radius);
}

double bl_point_distance(bl_point *p0, bl_point *p1) {
  double dx = p0->x - p1->x;
  double dy = p0->y - p1->y;
  return sqrt(dx * dx + dy * dy);
}

double bl_point_magnitude(bl_point *p) {
  return sqrt(p->x * p->x + p->y * p->y);
}

double bl_point_angle(bl_point *p) {
  return atan2(p->y, p->x);
}

void bl_point_translate(bl_point *p, double x, double y) {
  p->x += x;
  p->y += y;
}

void bl_point_scale(bl_point *p, double sx, double sy) {
  p->x *= sx;
  p->y *= sy;
}

void bl_point_rotate(bl_point *p, double angle) {
  double x = p->x * cos(angle) + p->y * sin(angle);
  double y = p->y * cos(angle) - p->x * sin(angle);
  p->x = x;
  p->y = y;
}

