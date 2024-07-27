#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n) {
  int i;
  for (i = 0; i < n; i++) {
    dest[i] = src[i] ? src[i] : '\0';
  }
  return dest;
}
int main() {
  char src[20] = "Hello, World!";
  char dest[20];
  ft_strncpy(dest, src, 20);
  printf("%s\n", dest);
  printf("%s\n", &dest[13]);
}
