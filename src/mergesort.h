#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#ifndef __TYPES_H__
#include "types.h"
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

void merge_sort(Point *array[],
                Point *temp[],
                int start,
                int end,
                int (*compare)(const Point *, const Point *));

#endif
