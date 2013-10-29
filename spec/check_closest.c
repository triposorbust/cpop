#ifndef __CHECK_CLOSEST_H__
#include "check_closest.h"
#endif


START_TEST (test_closest)
{
  int x,y;
  x = 7;
  y = 9;
  ck_assert_int_eq(7, x);
  ck_assert_int_eq(9, y);
}
END_TEST


Suite *closest_suite(void)
{
  Suite *s = suite_create("closest_pair");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_closest);

  suite_add_tcase(s, tc_core);
  return s;
}
