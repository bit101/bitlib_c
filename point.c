#include <malloc.h>
#include "point.h"

point* make_point(double x, double y)
{
  point *p;
  p = malloc(sizeof(point));
  p->x = x;
  p->y = y;
  p->next = NULL;
  return p;
}

void add_point(point *head, double x, double y)
{
  point *curr;
  point *next;
  curr = head;
  while(curr->next != NULL)
  {
    curr = curr->next;
  }
  next = make_point(x, y);
  curr->next = next;
}

