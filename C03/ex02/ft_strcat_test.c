#include <stdio.h>
#include "ft_strcat.h"

int main() {
  char fname[] = "Youssef";
  char lname[] = " Bouryal";
  printf("My name is => %s\n", ft_strcat(fname, lname));
  printf("fname = %s\n", fname);
}
