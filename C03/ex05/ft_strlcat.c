#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {
  int i, j;

  for (i = 0; dest[i]; i++) {
  }
  for (j = 0; src[j] && i < size; i++, j++)
    dest[i] = src[j];

  dest[i] = '\0';

  return (unsigned int)i;
}

int main() {
  char first[] = "This is ";
  char last[] = "a potentially long string";
  int r;
  int size = 100;
  char buffer[size];

  strcpy(buffer, first);
  r = ft_strlcat(buffer, last, size);

  puts(buffer);
  printf("Value returned: %d\n", r);
  if (r > size)
    puts("String truncated");
  else
    puts("String was fully copied");

  return (0);
}
