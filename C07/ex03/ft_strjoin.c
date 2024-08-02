#include <stdlib.h>

int ft_strlen(char *str) {
  int i;

  for (i = 0; str[i]; i++) {
  }
  return i;
}

char *ft_strjoin(int size, char **strs, char *sep) {
  char *buffer;
  int buf_index;
  int join_strs_len;
  int sep_len;

  if (size <= 0)
    return NULL;
  // calculating the length of all the strings in strs including the separator
  sep_len = ft_strlen(sep);
  join_strs_len = 0;
  for (int i = 0; i < size; i++) {
    join_strs_len += ft_strlen(strs[i]);
    join_strs_len += sep_len;
  }
  buffer = (char *)malloc(sizeof(char) * join_strs_len + 1);
  if (!buffer)
    return NULL;
  // Concatinating the strings
  buf_index = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < ft_strlen(strs[i]); j++)
      buffer[buf_index++] = strs[i][j];
    if (i != size - 1)
      for (int j = 0; j < sep_len; j++)
        buffer[buf_index++] = sep[j];
  }
  buffer[join_strs_len] = '\0';
  return buffer;
}

int main() {
  char *strs[] = {
      "Good Morning", "Good Afternoon", "Goodbye", "Salut", "Hey", "Fuckoff",
  };
  char *joined_str = ft_strjoin(6, strs, " | ");
  printf("the joined str -> %s\n", joined_str);
  free(joined_str);
  return 0;
}
