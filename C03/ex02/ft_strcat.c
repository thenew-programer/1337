#include <stdio.h>

char *ft_strcat(char *dest, char *src) {
  int i, j;

  for (i = 0; dest[i]; i++) {
  }
  for (j = 0; src[j]; i++, j++)
    dest[i] = src[j];
  dest[i] = '\0';
  return dest;
}

int main() {
  char str1[100] = "Youssef-";
  char str2[] = "Bouryal!";
  ft_strcat(str1, str2);
  printf("%s\n", str1);
}
