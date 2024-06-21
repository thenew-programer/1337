#include <stdio.h>
#include "ft_strcmp.h"

int main() {
  char name[20] = "Youssef";
  char _name[20] = "Youssef";
  printf("name == _name : %s\n",
         ft_strcmp(name, _name) == 0 ? "True" : "False");
  return (0);
}
