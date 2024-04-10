#include "include.h"
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size) {
  int i, j, tmp;
  for (i = 0, j = size - 1; i < size / 2; i++, j--) {
    tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
  }
}
