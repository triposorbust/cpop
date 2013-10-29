#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __CLOSEST_H__
#include "closest.h"
#endif

#ifndef __TYPES_H__
#include "types.h"
#endif

#define INITIAL_SIZE (10)

size_t resize(Point **ppoints, size_t current)
{
  Point *points = *ppoints;
  Point *newpoints = (Point *) malloc(2*current * sizeof(Point));

  size_t i;
  for (i=0; i<current; ++i) {
    newpoints[i].x = points[i].x;
    newpoints[i].y = points[i].y;
  }

  free(points);
  *ppoints = newpoints;
  return 2*current;
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("Usage:\n$ closest-pair <some-filename>\n");
    exit(1);
  }

  char *filename = argv[1];
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Couldn't open file \"%s\"!\nFailing ungracefully.\n", filename);
    exit(1);
  }

  size_t n = 0;
  size_t capacity = INITIAL_SIZE;
  Point *points = (Point *) malloc(capacity * sizeof(Point));

  int x,y;
  while (fscanf(f, "%d%d\n", &x, &y) == 2) {
    if (n >= capacity)
      capacity = resize(&points, capacity);
    points[n].x = x;
    points[n].y = y;
    ++n;
  }

  RESULT closest = closest_pair(points, n);

  printf("(x1,y1) = (%d,%d)\n", (closest->p)->x, (closest->p)->y);
  printf("(x2,y2) = (%d,%d)\n", (closest->q)->x, (closest->q)->y);
  printf("distance = %g\n", closest->dist);

  free_result(closest);

  free(points);
  fclose(f);
  return 0;
}
