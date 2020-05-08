#include <malloc.h>
#include "point.h"

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
  p->next = NULL;
  return p;
}

void add_point(point_list *head, double x, double y)
{
  point *curr = head->next;
  point *next = make_point(x, y);
  if (curr == NULL)
  {
    head->next = next;
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

