#include <stdio.h>

int ft_strcmp(char *s1, char *s2) {
  for (int i = 0; s1[i] || s2[i]; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] - s2[i]);
    }
  }
  return (0);
}

void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *)) {
  char *tmp;
  for (int i = 0; tab[i + 1]; i++) {
    for (int j = i + 1; tab[j]; j++) {
      if (cmp(tab[i], tab[j]) > 0) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
      }
    }
  }
}

int main(void) {
  char *tab[] = {"HelloA",       "Hello",     "World",
                 "Zsdlkfjwelkf", "Gladiator", "Azaar"};

  printf("\tBefore Sorting\n");
  for (int i = 0; tab[i]; i++) {
    printf("[%d] %s\n", i, tab[i]);
  }
  ft_advanced_sort_string_tab(tab, ft_strcmp);
  printf("\tAfter Sorting\n");
  for (int i = 0; tab[i]; i++) {
    printf("[%d] %s\n", i, tab[i]);
  }
  return (0);
}
