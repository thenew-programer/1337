#include "../include.h"

void ft_print_alphabet(void) {
  for (char i = 97; i < 123; i++) {
    write(1, &i, 1);
    write(1, "\n", 1);
  }
}
