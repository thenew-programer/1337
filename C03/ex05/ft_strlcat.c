#include "ft_strlcat.h"

unsigned int ft_strlen(char *str) {
  unsigned int i;
  for (i = 0; str[i]; i++) {}
  return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {

  unsigned int dest_len, src_len;
  int i, j;

  dest_len = ft_strlen(dest);
  src_len = ft_strlen(src);

  for (i = dest_len, j = 0; i < size - 1; i++, j++) {
    dest[i] = src[j];
  }
  dest[size + 1] = '\0';


  return (dest_len + src_len);
}
