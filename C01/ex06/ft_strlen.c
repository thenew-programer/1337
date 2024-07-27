#include <string.h>
#include <unistd.h>

int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

int main() {
  char str[] = "Hello, World!";
  int ft_len = ft_strlen(str);
  int len = strlen(str);
  if (len == ft_len)
    write(1, "OK\n", 3);
  else
    write(1, "FAIL\n", 5);
}
