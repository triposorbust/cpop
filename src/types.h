#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct {
  int x,y;
} Point;

typedef struct {
  Point *p;
  Point *q;
  double dist;
} Result;

#endif
