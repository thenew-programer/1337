
int ft_str_is_lowercase(char *str) {
  if (!str)
    return 1;

  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      continue;
    else
      return (0);
  }
  return 1;
}
