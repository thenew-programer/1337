#include <stdio.h>

char *ft_strcpy(char *dest, char *src) {
  int i;
  for (i = 0; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

int main() {
  char str1[20] = "Youssef Bouryal";
  char str2[20];
  ft_strcpy(str2, str1);
  printf("%s\n", str2);
  return (0);
}
