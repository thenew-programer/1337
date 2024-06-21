#include "ft_strncmp.h"


int ft_strncmp(char *s1, char *s2, unsigned int size) {

  unsigned int i;
  for (i = 0; i < size && (*s1 || *s2) && (*s1 == *s2); i++) {
    s1++;
    s2++;
  }
  return (int)(*s1 - *s2);
}
