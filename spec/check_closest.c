#ifndef __CHECK_CLOSEST_H__
#include "check_closest.h"
#endif


static void random_points(Point *points, int n)
{
  srand(time(NULL));

  int i;
  for (i=0; i<n; ++i) {
    points[i].x = (rand() % 4500000) - 2250000;
    points[i].y = (rand() % 4500000) - 2250000;
  }
}

static int consistent(Result *a, Result *b)
{
  return (a->dist - b->dist) <= DBL_EPSILON;
}

static double distance(Point *p,
                       Point *q)
{
  int dx = p->x - q->x;
  int dy = p->y - q->y;
  double dist = sqrt((double) (dx*dx + dy*dy));
  return dist;
}

static Result *naive_closest_pair(Point *points,
                                  int n)
{
  Result *result = (Result *) malloc(sizeof(Result));
  result->dist = DBL_MAX;

  int i,j;
  for (i=0; i<n; ++i) {
    for (j=i+1; j<n; ++j) {
      double dij = distance(&points[i], &points[j]);
      if (dij < result->dist) {
        result->p = &points[i];
        result->q = &points[j];
        result->dist = dij;
      }
    }
  }

  return result;
}

START_TEST (test_closest_small)
{
  int n=10;
  Point *points = (Point *) malloc(n * sizeof(Point));
  random_points(points, n);

  Result *expected = naive_closest_pair(points, n);
  RESULT closest = closest_pair(points, n);
  free(points);

  ck_assert(consistent(expected, closest));
  free(expected);
  free_result(closest);
}
END_TEST


START_TEST (test_closest_large)
{
  int n=10000;
  Point *points = (Point *) malloc(n * sizeof(Point));
  random_points(points, n);

  Result *expected = naive_closest_pair(points, n);
  RESULT closest = closest_pair(points, n);
  free(points);

  ck_assert(consistent(expected, closest));
  free(expected);
  free_result(closest);
}
END_TEST


Suite *closest_suite(void)
{
  Suite *s = suite_create("closest_pair");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_closest_small);
  tcase_add_test(tc_core, test_closest_large);

  suite_add_tcase(s, tc_core);
  return s;
}
