#ifndef __CHECK_MERGESORT_H__
#define __CHECK_MERGESORT_H__

#ifndef __CHECK_H__
#define __CHECK_H__
#include <check.h>
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __TIME_H__
#define __TIME_H__
#include <time.h>
#endif

#ifndef __MERGESORT_H__
#include "../src/mergesort.h"
#endif

#ifndef __COMPARE_H__
#include "../src/compare.h"
#endif

#ifndef __TYPES_H__
#include "../src/types.h"
#endif

Suite *mergesort_suite(void);

#endif
