#include "include.h"
#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod) {
  *div = (int)(a / b);
  *mod = a % b;
}
