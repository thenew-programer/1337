#include "ft_strstr.h"

int ft_strlen(char *str) {
  int i;

  for (i = 0; str[i]; i++) {}
  
  return (i);
}

char *ft_strstr(char *str, char *to_find) {
  int str_len, tf_len;

  str_len = ft_strlen(str);
  tf_len = ft_strlen(to_find);

  for (int i = 0; i <= (str_len - tf_len); i++) {
    int j;

    for (j = 0; j < tf_len; j++) {
      if (to_find[j] != str[i + j])
        break;
    }

    if (j == tf_len)
      return (str + i);
  }
  return (0);
}
