#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str) {
  int i = 0;

  for (i = 0; str[i]; i++) {
  }
  return i;
}

char *ft_strdup(char *src) {
  int i, src_len;
  char *new_str;

  src_len = ft_strlen(src);
  new_str = (char *)malloc(sizeof(char) * (src_len + 1));
  if (!new_str)
    return 0;

  for (i = 0; i < src_len; i++) {
    new_str[i] = src[i];
  }
  new_str[i] = '\0';
  return new_str;
}

int main() {
  char str[] = "Hello world!";
  char *str_cpy = ft_strdup(str);
  printf("Original string: %s\n", str);
  printf("Copied string: %s\n", str_cpy);
  free(str_cpy);
  return 0;
}
