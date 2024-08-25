#include "ft.h"

int ft_strcmp(char *s1, char *s2) {
  for (int i = 0; s1[i] || s2[i]; i++) {
    if (s1[i] != s2[i])
      return (int)(s1[i] - s2[i]);
  }
  return 0;
}
