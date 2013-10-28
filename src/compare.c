#ifndef __COMPARE_H__
#include "compare.h"
#endif

int compare_xs(const Point *p, const Point *q)
{
  int px = p->x;
  int qx = q->x;

  if (px < qx)
    return -1;
  else if (px > qx)
    return  1;
  else
    return 0;
}

int compare_ys(const Point *p, const Point *q)
{
  int py = p->y;
  int qy = q->y;

  if (py < qy)
    return -1;
  else if (py > qy)
    return  1;
  else
    return 0;
}
