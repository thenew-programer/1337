#include "../include.h"

void ft_print_reverse_alphabet(void) {
  for (char i = 122; i > 96; i--) {
    write(1, &i, 1);
    write(1, "\n", 1);
  }
}
