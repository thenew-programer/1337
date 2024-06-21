#include <stdio.h>
#include "ft_strncat.h"

int main() {
  char lname[] = "Youssef";
  char fname[] = " Bouryallllllllll";
  printf("Full Name => %s\n", ft_strncat(lname, fname, 8));
}
