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

#define ULIMIT (100)

int main(int argc, char **argv)
{
  srand(time(NULL));
  printf("Odelay!\n");
  return 0;
}
