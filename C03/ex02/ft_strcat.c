#include "ft_strcat.h"

char *ft_strcat(char *dest, char *src) {
  char new_str[1000];

  int i, j;
  for (i = 0; dest[i]; i++) {
    new_str[i] = dest[i];
  }
  for (j = 0;src[j]; j++, i++) {
    new_str[i] = src[j];
  }
  new_str[i] = '\0';
  dest = new_str;
  return dest;
}
