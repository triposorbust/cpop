#ifndef __CLOSEST_H__
#define __CLOSEST_H__

#ifndef __TYPES_H__
#include "types.h"
#endif

#ifndef __COMPARE_H__
#include "compare.h"
#endif

#ifndef __MERGESORT_H__
#include "mergesort.h"
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __CMATH_H__
#define __CMATH_H__
#include <math.h>
#endif

#ifndef __FLOAT_H__
#define __FLOAT_H__
#include <float.h>
#endif

#define MIN(X,Y)  ((X) <= (Y) ? (X) : (Y))

Result *closest_pair(Point *points, size_t n);
void free_result(Result *);

#endif
