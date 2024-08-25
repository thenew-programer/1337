#include <stdio.h>

int compare(int a, int b) { return (a - b); }

int ft_is_sort(int *tab, int length, int (*f)(int, int)) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (f(tab[i], tab[j]) > 0) {
        return (0);
      }
    }
  }
  return (1);
}

int main(void) {
  int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = 10;

  printf("is tab sorted => %s\n",
         ft_is_sort(tab, len, compare) ? "True" : "False");
  return (0);
}
