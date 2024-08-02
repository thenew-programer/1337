#include <unistd.h>

void ft_putstr(char *str) {
  for (int i = 0; str[i]; i++) {
    write(1, &str[i], 1);
  }
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    ft_putstr(argv[i]);
    write(1, "\n", 1);
  }
}
