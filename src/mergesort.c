#ifndef __MERGESORT_H__
#include "mergesort.h"
#endif

static
void
merge(Point *array[],
      Point *temp[],
      int start,
      int mid,
      int end,
      int (*compare)(const Point *, const Point *))
{
  int i,j,k;
  i = start;
  j = mid+1;
  k = start;

  while (i <= mid && j <= end) {
    if (compare(array[i], array[j]) <= 0)
      temp[k++] = array[i++];
    else
      temp[k++] = array[j++];
  }

  while (i <= mid) temp[k++] = array[i++];
  while (j <= end) temp[k++] = array[j++];

  for (k=start; k<=end; ++k)
    array[k] = temp[k];
}

void
merge_sort(Point *array[],
           Point *temp[],
           int start,
           int end,
           int (*compare)(const Point *, const Point *))
{
  if (start < end) {
    int mid = (start + end)/2;
    merge_sort(array, temp, start, mid, compare);
    merge_sort(array, temp, mid+1, end, compare);
    merge(array, temp, start, mid, end, compare);
  }
}
