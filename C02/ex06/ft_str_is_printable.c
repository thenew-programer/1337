int ft_str_is_printable(char *str) {
  if (!str)
    return 1;

  for (int i = 0; str[i]; i++) {
    if (str[i] >= 32 && str[i] <= 126)
      continue;
    else
      return 0;
  }
  return 1;
}

int main() {
  char *str0;
  char str1[] = {3, 1, 11, 30, 20, 55};
  char str2[] = "$@!@# )*()";
  printf("str0 -> %d\n", ft_str_is_printable(str0));
  printf("str1 -> %d\n", ft_str_is_printable(str1));
  printf("str2 -> %d\n", ft_str_is_printable(str2));
}
