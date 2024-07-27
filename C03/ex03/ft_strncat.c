#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb) {
  int i, j;

  for (i = 0; dest[i]; i++) {
  }

  for (j = 0; src[j] && j < nb; j++, i++)
    dest[i] = src[j];

  dest[i] = '\0';
  return dest;
}

int main() {
  char str1[100] = "Hello world. ";
  char str2[] = "Hello again. What do You do?";
  printf("%s\n", ft_strncat(str1, str2, 30));
}
