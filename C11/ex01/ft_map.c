#include <stdlib.h>

int *ft_map(int *tab, int length, int (*f)(int)) {
  int *altered_tab;

  altered_tab = (int *)malloc(sizeof(int) * length);
  if (!altered_tab)
    return NULL;

  for (int i = 0; i < length; i++) {
    altered_tab[i] = f(tab[i]);
  }
  return (altered_tab);
}
