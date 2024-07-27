int ft_str_is_numeric(char *str) {
  if (!str)
    return 1;

  for (int i = 0; str[i]; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      continue;
    else
      return 0;
  }
  return 1;
}

int main() {
  char *str0;
  char str1[] = "1234567";
  char str2[] = "123a023";
  printf("str0 -> %d\n", ft_str_is_numeric(str0));
  printf("str1 -> %d\n", ft_str_is_numeric(str1));
  printf("str2 -> %d\n", ft_str_is_numeric(str2));
}
