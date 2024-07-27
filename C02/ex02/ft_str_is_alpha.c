int ft_str_is_alpha(char *str) {
  if (!str)
    return 1;
  for (int i = 0; str[i]; i++) {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
      continue;
    else
      return 0;
  }
  return 1;
}

int main() {
  char str[] = "Helloworld";
  int hello_world = ft_str_is_alpha(str);
  char str1[] = "bojos0";
  int bojos0 = ft_str_is_alpha(str1);
  printf("str -> %d\nstr1 -> %d\n", hello_world, bojos0);
}
