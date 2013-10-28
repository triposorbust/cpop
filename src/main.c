#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __TIME_H__
#define __TIME_H__
#include <time.h>
#endif

#ifndef __FUNCTIONS_H__
#include "functions.h"
#endif

#define ULIMIT (100)

int main(int argc, char **argv)
{
  int x,y,fres,gres;
  srand(time(NULL));

  x = rand() % ULIMIT;
  y = rand() % ULIMIT;

  fres = f(x,y);
  gres = g(x,y);

  printf("f(%2d,%2d) = %2d \n", x, y, fres);
  printf("g(%2d,%2d) = %2d \n", x, y, gres);

  return 0;
}
