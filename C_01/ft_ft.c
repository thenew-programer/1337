#include "include.h"
#include <stdio.h>

void ft_ft(int *nbr) {
  // pointer;
  *nbr = 42;
  printf("nbr after mutating: %d\n", *nbr);
  ft_ft_1(&nbr);
  printf("nbr after mutating: %d\n", *nbr);
}
