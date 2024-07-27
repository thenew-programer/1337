#include <stdio.h>

void ft_swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void selection_sort(int *tab, int size) {

  for (int i = 0; i < size - 1; i++) {
    int min = i;

    for (int j = i + 1; j < size - 1; j++) {
      if (tab[j] < tab[min])
        min = j;
    }

    if (min != size - 1)
      ft_swap(&tab[min], &tab[i]);
  }
}
void bubble_sort(int *tab, int size) {
  int swapped;
  while (1) {
    swapped = 0;
    for (int i = 0, j = i + 1; i < size - 1; i++, j++) {
      if (tab[i] > tab[j]) {
        ft_swap(&tab[i], &tab[j]);
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}
void ft_sort_int_tab(int *tab, int size) {
  bubble_sort(tab, size);
  // selection_sort(tab, size);
}

int main() {
  int size = 10;
  int tab[10] = {1, 4, 2, 9, 7, 5, 0, 8, 3, 6}; // unsorted
  // int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted
  for (int i = 0; i < size; i++)
    printf("%d, ", tab[i]);
  printf("\n");
  ft_sort_int_tab(tab, size);
  for (int i = 0; i < size; i++)
    printf("%d, ", tab[i]);
  printf("\n");
}
