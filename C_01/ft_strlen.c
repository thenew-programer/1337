#include "include.h"

int ft_strlen(char *str) {
  int i, size;
  i = size = 0;
  while (str[i++] != '\0')
    size++;
  return (size);
}
