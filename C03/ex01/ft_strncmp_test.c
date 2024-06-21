#include <stdio.h>
#include "ft_strncmp.h"

int main() {
  char name[20] = "Youssef";
  char _name[20] = "Yousjef";
  printf("name == _name : %s\n",
         ft_strncmp(name, _name, 3) == 0 ? "True" : "False");
  return (0);
}
