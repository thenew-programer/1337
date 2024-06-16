#include "../include.h"

void ft_print_numbers(void) {
  for (char i = 48; i < 58; i++) {
    write(1, &i, 1);
    write(1, "\n", 1);
  }
}
