#ifndef __CLOSEST_H__
#include "closest.h"
#endif

static double _distance(Point *p,
                        Point *q)
{
  int dx = p->x - q->x;
  int dy = p->y - q->y;
  double dist = sqrt((double) (dx*dx + dy*dy));
  return dist;
}

static Result *_brute_force_closest_pair(Point **points,
                                         int n)
{
  Result *result = (Result *) malloc(sizeof(Result));
  result->dist = DBL_MAX;

  int i,j;
  for (i=0; i<n; ++i) {
    for (j=i+1; j<n; ++j) {
      double dij = _distance(points[i], points[j]);
      if (dij < result->dist) {
        result->p = points[i];
        result->q = points[j];
        result->dist = dij;
      }
    }
  }

  return result;
}

static void _split_points_at(Point **orig,
                             Point **left,
                             Point **right,
                             int line_x,
                             int n)
{
  int i,j,k;
  j = 0; k = 0;
  for (i=0; i<n; ++i) {
    if (orig[i]->x <= line_x) left[j++]  = orig[i];
    else                      right[k++] = orig[i];
  }
}

static void _copy(Result *src,
                  Result *dest)
{
  dest->p = src->p;
  dest->q = src->q;
  dest->dist = src->dist;
}

static Result *_closest_crossing_pair(Point **y_sorted,
                                      int line_x,
                                      double dist,
                                      int n)
{
  Result *result = (Result *) malloc(sizeof(Result));
  int n_within = 0;

  int i,j;
  for (i=0; i<n; ++i)
    if ((double) abs(dist - y_sorted[i]->x) <= dist)
      n_within += 1;

  Point **points = (Point **) malloc(n_within * sizeof(Point *));
  for (i=0,j=0; i<n; ++i)
    if ((double) abs(dist - y_sorted[i]->x) <= dist)
      points[j++] = y_sorted[i];

  result->dist = DBL_MAX;
  for (i=0; i<n_within; ++i) {
    for (j=i+1; j<=i+7 && j<n_within; ++j) {
      double dij = _distance(points[i], points[j]);
      if (dij <= result->dist) {
        result->p = points[i];
        result->q = points[j];
        result->dist = dij;
      }
    }
  }

  return result;
}

static Result *_closest_pair(Point **x_sorted,
                             Point **y_sorted,
                             int n)
{
  if (n <= 3) return _brute_force_closest_pair(x_sorted, n);
  Result *result = (Result *) malloc(sizeof(Result));

  int line_x = x_sorted[n/2]->x;
  int n_left  = 0;
  int n_right = 0;

  int i;
  for (i=0; i<n; ++i) {
    if (x_sorted[i]->x <= line_x) n_left  += 1;
    else                          n_right += 1;
  }

  Point **x_sorted_left  = (Point **) malloc(sizeof(Point *) * n_left);
  Point **x_sorted_right = (Point **) malloc(sizeof(Point *) * n_right);
  _split_points_at(x_sorted, x_sorted_left, x_sorted_right, line_x, n);

  Point **y_sorted_left  = (Point **) malloc(sizeof(Point *) * n_left);
  Point **y_sorted_right = (Point **) malloc(sizeof(Point *) * n_right);
  _split_points_at(y_sorted, y_sorted_left, y_sorted_right, line_x, n);

  Result *left_result  = _closest_pair(x_sorted_left,  y_sorted_left,  n_left);
  Result *right_result = _closest_pair(x_sorted_right, y_sorted_right, n_right);

  free(x_sorted_left);
  free(x_sorted_right);
  free(y_sorted_left);
  free(y_sorted_right);

  double dmin = MIN(left_result->dist, right_result->dist);
  Result *mid_result = _closest_crossing_pair(y_sorted, line_x, dmin, n);

  double dleft,dmid,dright;
  dmid   =   mid_result->dist;
  dleft  =  left_result->dist;
  dright = right_result->dist;

  if (dleft  <= dmid  && dleft  <= dright) _copy(left_result,  result);
  if (dmid   <= dleft && dmid   <= dright) _copy(mid_result,   result);
  if (dright <= dmid  && dright <= dleft)  _copy(right_result, result);

  free(mid_result);
  free(left_result);
  free(right_result);

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

  Result *result = _closest_pair(x_sorted, y_sorted, n);

  free(temp);
  free(x_sorted);
  free(y_sorted);
  return result;
}

void free_result(Result *result)
{
  if (result != NULL) free(result);
}
