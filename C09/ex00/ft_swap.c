#include "ft.h"

void ft_swap(int *a, int *b) {
  *a += *b;
  *b = *a - *b;
  *a = *a - *b;
}
