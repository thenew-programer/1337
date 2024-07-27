#include <stdio.h>

void ft_swap(int *a, int *b) {
  *a = *b + *a;
  *b = *a - *b;
  *a = *a - *b;
}

int main() {
  int a = 10;
  int b = 11;
  printf("a = %d\nb = %d\n", a, b);
  ft_swap(&a, &b);
  printf("a = %d\nb = %d\n", a, b);
}
