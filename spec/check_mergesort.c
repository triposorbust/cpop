#ifndef __CHECK_MERGESORT_H__
#include "check_mergesort.h"
#endif


START_TEST (test_sort)
{
  int x,y;
  x = 3;
  y = 5;
  ck_assert_int_eq(3, x);
  ck_assert_int_eq(5, y);
}
END_TEST


Suite *mergesort_suite(void)
{
  Suite *s = suite_create("mergesort");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_sort);

  suite_add_tcase(s, tc_core);
  return s;
}
