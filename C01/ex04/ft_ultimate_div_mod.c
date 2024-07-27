#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b) {
  int div, mod;
  div = *a / *b;
  mod = *a % *b;
  *a = div;
  *b = mod;
}

int main() {
  int a = 10, b = 4;
  printf("%d / %d = ", a, b);
  ft_ultimate_div_mod(&a, &b);
  printf("%d -> remainder: %d\n", a, b);
}
