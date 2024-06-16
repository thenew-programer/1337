#include "include.h"
#include <unistd.h>

void ft_putstr(char *str) {
  int size = 0;
  int i = 0;
  while (str[i++] != '\0')
    size++;
  write(STDOUT_FILENO, str, size);
}
