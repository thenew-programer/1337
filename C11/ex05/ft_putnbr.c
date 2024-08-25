#include "do-op.h"
#include <unistd.h>

static char *convert_int_to_str(int nb, char *buffer) {
  int i;
  int tmp;
  int len;

  i = 0;
  if (nb == 0) {
    buffer[i++] = '0';
    buffer[i] = '\0';
    return buffer;
  }
  tmp = nb;
  len = 0;
  while (tmp) {
    len++;
    tmp /= 10;
  }
  buffer[len] = '\0';
  while (nb) {
    buffer[--len] = (nb % 10) + '0';
    nb /= 10;
  }

  return buffer;
}

void ft_putnbr(int nb) {
  char buffer[20];
  convert_int_to_str(nb, buffer);
  for (int i = 0; buffer[i]; i++)
    write(1, &buffer[i], 1);
  write(1, "\n", 1);
}
