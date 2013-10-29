#ifndef __CHECK_MERGESORT_H__
#include "check_mergesort.h"
#endif


START_TEST (test_sort)
{
  srand(time(NULL));
  size_t n = 10;
  Point *points = (Point *) malloc(n * sizeof(Point));
  Point **xpointers = (Point **) malloc(n * sizeof(Point *));
  Point **ypointers = (Point **) malloc(n * sizeof(Point *));
  Point **auxiliary = (Point **) malloc(n * sizeof(Point *));
  if (!points || !xpointers || !ypointers || !auxiliary) exit(EXIT_FAILURE);

  int i;
  for (i=0; i<n; ++i) {
    points[i].x = rand() % 1000;
    points[i].y = rand() % 1000;
    xpointers[i] = &points[i];
    ypointers[i] = &points[i];
  }

  merge_sort(xpointers, auxiliary, 0, n-1, &compare_xs);
  merge_sort(ypointers, auxiliary, 0, n-1, &compare_ys);

  for (i=0; i<n-1; ++i) {
    ck_assert_int_le(xpointers[i]->x, xpointers[i+1]->x);
    ck_assert_int_le(ypointers[i]->y, ypointers[i+1]->y);
  }

  free(auxiliary);
  free(ypointers);
  free(xpointers);
  free(points);
}
END_TEST


Suite *mergesort_suite(void)
{
  Suite *s = suite_create("merge_sort");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_sort);

  suite_add_tcase(s, tc_core);
  return s;
}
