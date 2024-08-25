#include <stdio.h>

int ft_strcmp(char *s1, char *s2) {
  for (int i = 0; s1[i] || s2[i]; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] - s2[i]);
    }
  }
  return (0);
}
void ft_sort_string_tab(char **tab) {
  char *tmp;

  for (int i = 0; tab[i + 1]; i++) {
    for (int j = i + 1; tab[j]; j++) {
      if (ft_strcmp(tab[i], tab[j]) > 0) {
        tmp = tab[j];
        tab[j] = tab[i];
        tab[i] = tmp;
      }
    }
  }
}

int main(void) {
  char *tab[] = {"Hello", "HEllo", "AZIZA",
                 "Hamid", "slmlm", "wekljldkfjwle32"};
  printf("\tBefore sorting\n");
  for (int i = 0; tab[i]; i++) {
    printf("[%d] %s\n", i, tab[i]);
  }
  ft_sort_string_tab(tab);
  printf("\tAfter sorting\n");
  for (int i = 0; tab[i]; i++) {
    printf("[%d] %s\n", i, tab[i]);
  }
  return (0);
}
