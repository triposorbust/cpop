#ifndef __CHECK_FUNCTIONS_H__
#include "check_functions.h"
#endif


START_TEST (test_f)
{
  int x,y;
  x = 3;
  y = 5;
  ck_assert_int_eq(x+y, f(x,y));
}
END_TEST


START_TEST (test_g)
{
  int x,y;
  x = 7;
  y = 9;
  ck_assert_int_eq(x*y, g(x,y));
}
END_TEST


Suite *function_suite(void)
{
  Suite *s = suite_create("functions");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_f);
  tcase_add_test(tc_core, test_g);

  suite_add_tcase(s, tc_core);
  return s;
}
