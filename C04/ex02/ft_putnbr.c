#include <unistd.h>

char *convert_int_to_str(int nb, char *buffer) {
  int i = 0;

  // if nb is 0
  if (nb == 0) {
    buffer[i++] = '0';
    buffer[i] = '\0';
    return buffer;
  }

  // calc of the length of the number
  int tmp = nb;
  int len = 0;
  while (tmp) {
    len++;
    tmp /= 10;
  }

  // converting int to str
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
}
int main() {
  ft_putnbr(0);
  write(1, "\n", 1);
  ft_putnbr(42);
  write(1, "\n", 1);
  ft_putnbr(1337);
  write(1, "\n", 1);
}
