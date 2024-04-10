#include "include.h"

void ft_ultimate_div_mod(int *a, int *b) {
  int tmp = *a;
  *a = (int)((*a) / (*b));
  *b = tmp % *b;
}
