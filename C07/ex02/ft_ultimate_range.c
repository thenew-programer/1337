#include <stdlib.h>

int *ft_range(int min, int max) {
  int arr_len, range_idx;
  int *range;

  range_idx = 0;
  arr_len = max - min;
  if (arr_len <= 0)
    return NULL;
  range = (int *)malloc(sizeof(int) * arr_len);
  if (!range)
    return NULL;

  for (int i = min; i < max; i++) {
    range[range_idx++] = i;
  }
  return range;
}

int ft_ultimate_range(int **range, int min, int max) {
  *range = ft_range(min, max);
  if (!*range)
    return -1;
  else
    return max - min;
}

int main() {
  int *range;
  ft_ultimate_range(&range, 99, 100);
  printf("\t\tRANGE\n");
  if (!range) {
    printf("None\n");
    return -1;
  }
  for (int i = 0; i < 99 - 1; i++) {
    printf("range[%d] = %d\n", i, range[i]);
  }
  free(range);
}
