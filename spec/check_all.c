#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __CHECK_MERGESORT_H__
#include "check_mergesort.h"
#endif

#ifndef __CHECK_CLOSEST_H__
#include "check_closest.h"
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

  Suite *ms = mergesort_suite();
  Suite *cs = closest_suite();

  number_failed += run_suite(ms);
  number_failed += run_suite(cs);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
