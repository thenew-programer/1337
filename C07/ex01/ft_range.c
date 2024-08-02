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

int main() {
  int *range = ft_range(1, 100);
  printf("\t\tRANGE\n");
  if (!range) {
    printf("None\n");
    return -1;
  }
  for (int i = 0; range[i]; i++) {
    printf("range[%d] = %d\n", i, range[i]);
  }
  free(range);
}
