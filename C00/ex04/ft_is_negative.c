#include "../include.h"

void ft_is_negative(int n) {
  if (n >= 0)
    write(1, "P\n", 2);
  else
    write(1, "N\n", 2);
}
