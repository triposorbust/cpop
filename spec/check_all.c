#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __CHECK_FUNCTIONS_H__
#include "check_functions.h"
#endif

#ifndef __CHECK_MERGESORT_H__
#include "check_mergesort.h"
#endif

static int run_suite(Suite *s)
{
  int number_failed;
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

int main(void)
{
  int number_failed = 0;

  Suite *fs = function_suite();
  Suite *ms = mergesort_suite();

  number_failed += run_suite(fs);
  number_failed += run_suite(ms);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
