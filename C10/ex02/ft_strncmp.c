#include "ft_tail.h"

int ft_strncmp(char *s1, char *s2, unsigned int n) {
  unsigned int i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n) {
    if (s1[i] != s2[i])
      return (int)(s1[i] - s2[i]);
    i++;
  }
  return 0;
}