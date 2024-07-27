#include <stdio.h>
void ft_swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void ft_rev_int_tab(int *tab, int size) {
  int i, j = size - 1;
  for (i = 0; i < j; i++, j--) {
    if (tab[i] == tab[j])
      continue;
    ft_swap(&tab[i], &tab[j]);
  }
}

int main() {
  int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  for (int i = 0; i < 11; i++)
    printf("%d, ", tab[i]);
  printf("\n");
  ft_rev_int_tab(tab, 11);
  for (int i = 0; i < 11; i++)
    printf("%d, ", tab[i]);
  printf("\n");
}
