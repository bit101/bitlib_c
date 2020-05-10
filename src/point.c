#include <math.h>
#include <malloc.h>
#include <gtk/gtk.h>
#include <stdbool.h>
#include "point.h"
#include "bitlib.h"

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
  p->tail = NULL;
  return p;
}

void bl_add_point_xy(bl_point_list *list, double x, double y) {
  bl_add_point(list, bl_make_point(x, y));
}

void bl_add_point(bl_point_list *list, bl_point *p) {
  if (list->head == NULL) {
    list->head = p;
    list->tail = p;
  } else {
    list->tail->next = p;
    list->tail = p;
  }
}

int bl_point_list_count(bl_point_list *list) {
  int count = 0;
  bl_point *curr = list->head;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

void bl_point_list_destroy(bl_point_list *list) {
  bl_point *curr = list->head;
  free(list);
  list = NULL;
  while(curr != NULL) {
    bl_point *next = curr->next;
    free(curr);
    curr = next;
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

bl_point* bl_random_point_in_triangle(bl_point *p0, bl_point *p1, bl_point *p2) {
  double s = g_random_double();
  double t = g_random_double();
  double a = 1.0 - sqrt(t);
  double b = (1.0 - s) * sqrt(t);
  double c = s * sqrt(t);
  return bl_make_point(a * p0->x + b * p1->x + c * p2->x, a * p0->y + b * p1->y + c * p2->y);
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

double bl_dot_product(bl_point* p0, bl_point *p1, bl_point *p2, bl_point *p3) {
  double dx0 = p1->x - p0->x;
  double dy0 = p1->y - p0->y;
  double dx1 = p3->x - p2->x;
  double dy1 = p3->y - p2->y;
  return dx0 * dx1 + dy0 * dy1;
}

double bl_angle_between(bl_point *p0, bl_point *p1, bl_point *p2, bl_point *p3) {
  double dp = bl_dot_product(p0, p1, p2, p3);
  double mag0 = bl_point_distance(p0, p1);
  double mag1 = bl_point_distance(p2, p3);
  return acos(dp / mag0 / mag1);
}

bl_point* bl_bezier_point(bl_point *p0, bl_point *p1, bl_point *p2, bl_point *p3, double t) {
  double one_minus_t = 1.0 - t;
  double m0 = one_minus_t * one_minus_t * one_minus_t;
  double m1 = 3.0 * one_minus_t * one_minus_t * t;
  double m2 = 3.0 * one_minus_t * t * t;
  double m3 = t * t * t;
  return bl_make_point(
      m0 * p0->x + m1 * p1->x + m2 * p2->x + m3 * p3->x,
      m0 * p0->y + m1 * p1->y + m2 * p2->y + m3 * p3->y
  );
}

bl_point* bl_quadratic_point(bl_point *p0, bl_point *p1, bl_point *p2, double t) {
  double one_minus_t = 1.0 - t;
  double m0 = one_minus_t * one_minus_t;
  double m1 = 2.0 * one_minus_t * t;
  double m2 = t * t;
  return bl_make_point(
      m0 * p0->x + m1 * p1->x + m2 * p2->x,
      m0 * p0->y + m1 * p1->y + m2 * p2->y
  );
}

bl_point* bl_segment_intersect(bl_point *p0, bl_point *p1, bl_point *p2, bl_point *p3) {
  double a1 = p1->y - p0->y;
  double b1 = p0->x - p1->x;
  double c1 = a1*p0->x + b1*p0->y;
  double a2 = p3->y - p2->y;
  double b2 = p2->x - p3->x;
  double c2 = a2*p2->x + b2*p2->y;
  double denominator = a1*b2 - a2*b1;

  if (denominator == 0.0) {
    return NULL;
  }
  double intersectX = (b2*c1 - b1*c2) / denominator;
  double intersectY = (a1*c2 - a2*c1) / denominator;
  double rx0 = (intersectX - p0->x) / (p1->x - p0->x);
  double ry0 = (intersectY - p0->y) / (p1->y - p0->y);
  double rx1 = (intersectX - p2->x) / (p3->x - p2->x);
  double ry1 = (intersectY - p2->y) / (p3->y - p2->y);

  if (((rx0 >= 0.0 && rx0 <= 1.0) || (ry0 >= 0.0 && ry0 <= 1.0)) &&
      ((rx1 >= 0.0 && rx1 <= 1.0) || (ry1 >= 0.0 && ry1 <= 1.0))) {
    return bl_make_point( intersectX, intersectY);
  }
  return NULL;
}

bl_point* bl_tangent_point_to_circle(bl_point *p, double x, double y, double r, bool anticlockwise) {
  double d = bl_distance_xy(p->x, p->y, x, y);
  double dir = anticlockwise ? -1.0 : 1.0;
  double angle = cos(r / d) * dir;
  double baseAngle = atan2(y - p->y, x - p->x);
  double totalAngle = baseAngle + angle;

  return bl_make_point(
    x + cos(totalAngle) * r,
    y + sin(totalAngle) * r
  );
}
