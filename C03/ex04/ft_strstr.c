#include <stdio.h>

int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}
char *ft_strstr(char *str, char *to_find) {
  int i, j, haystack_len, needle_len;

  // if to_find is empty return the haystack and exit
  if (ft_strlen(to_find) == 0)
    return str;
  // finding the needle in the haystac
  haystack_len = ft_strlen(str);
  needle_len = ft_strlen(to_find);
  for (i = 0; i <= (haystack_len - needle_len); i++) {
    for (j = 0; j < needle_len; j++) {
      if (str[i + j] != to_find[j])
        break;
    }
    if (j == needle_len)
      return &str[i];
  }
  // Noting is found, return Null
  return 0;
}
int main() {
  char str1[] = "Hello World! world";
  char needle[] = "world";
  char *ret = ft_strstr(str1, needle);
  if (ret)
    printf("%s\n", ret);
  else {
    printf("Not Found\n");
  }
}
