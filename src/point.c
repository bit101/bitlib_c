#include <math.h>
#include <malloc.h>
#include <gtk/gtk.h>
#include "point.h"
#include "blmath.h"

point* make_point(double x, double y)
{
  point *p = (point*)malloc(sizeof(point));
  p->x = x;
  p->y = y;
  p->next = NULL;
  return p;
}

point_list* make_point_list()
{
  point_list *p = (point_list*)malloc(sizeof(point_list));
  p->head = NULL;
  return p;
}

void add_point_xy(point_list *list, double x, double y)
{
  add_point(list, make_point(x, y));
}

void add_point(point_list *list, point *p)
{
  point *curr = list->head;
  point *next = p;
  if (curr == NULL)
  {
    list->head = next;
  }
  else
  {
    while(curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = next;
  }
}

double point_distance(point *p0, point *p1)
{
  double dx = p0->x - p1->x;
  double dy = p0->y - p1->y;
  return sqrt(dx * dx + dy * dy);
}

point* lerp_point(double t, point *p0, point *p1)
{
  double x = bl_lerp(t, p0->x, p1->x);
  double y = bl_lerp(t, p0->y, p1->y);
  return make_point(x, y);
}

point* random_point(double x, double y, double w, double h)
{
  double px = g_random_double_range(x, x + w);
  double py = g_random_double_range(y, y + h);
  return make_point(px, py);
}

point* random_polar_point(double x, double y, double r)
{
  double angle = g_random_double_range(0, G_PI * 2);
  double radius = g_random_double_range(0, r);
  return make_point(x + cos(angle) * radius, y + sin(angle) * radius);
}

point* point_from_polar(double angle, double radius)
{
  return make_point(cos(angle) * radius, sin(angle)* radius);
}

double point_magnitude(point *p)
{
  return sqrt(p->x * p->x + p->y * p->y);
}

double point_angle(point *p)
{
  return atan2(p->y, p->x);
}

void point_translate(point *p, double x, double y)
{
  p->x += x;
  p->y += y;
}

void point_scale(point *p, double sx, double sy)
{
  p->x *= sx;
  p->y *= sy;
}

void point_rotate(point *p, double angle)
{
  double x = p->x * cos(angle) + p->y * sin(angle);
  double y = p->y * cos(angle) - p->x * sin(angle);
  p->x = x;
  p->y = y;
}

