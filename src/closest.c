#ifndef __CLOSEST_H__
#include "closest.h"
#endif

static double distance(Point *p,
                      Point *q)
{
  int dx = p->x - q->x;
  int dy = p->y - q->y;
  double dist = sqrt((double) (dx*dx + dy*dy));
  return dist;
}

static Result *_closest_pair(Point **x_sorted,
                             Point **y_sorted)
{
  Result *result = (Result *) malloc(sizeof(Result));
  return result;
}

Result *closest_pair(Point *points, size_t n)
{
  Point **x_sorted = (Point **) malloc(n * sizeof(Point *));
  Point **y_sorted = (Point **) malloc(n * sizeof(Point *));
  Point **temp = (Point **) malloc(n * sizeof(Point *));

  int i;
  for (i=0; i<n; ++i) {
    x_sorted[i] = &points[i];
    y_sorted[i] = &points[i];
  }
  merge_sort(x_sorted, temp, 0, n-1, &compare_xs);
  merge_sort(y_sorted, temp, 0, n-1, &compare_ys);

  Result *result = _closest_pair(x_sorted, y_sorted);

  free(temp);
  free(x_sorted);
  free(y_sorted);
  return result;
}

void free_result(Result *result)
{
  if (result != NULL) free(result);
}
