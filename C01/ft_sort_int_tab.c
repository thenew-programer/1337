#include "include.h"

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void ft_sort_int_tab(int *tab, int size) {
  int i, j;
  i = j = 0;
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      if (i == size - 1)
        continue;
      if (tab[i + 1] < tab[i])
        swap(&tab[i + 1], &tab[i]);
    }
  }
}
