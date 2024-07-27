int ft_str_is_uppercase(char *str) {
  if (!str)
    return 1;

  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      continue;
    else
      return (0);
  }
  return 1;
}
