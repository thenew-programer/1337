int ft_any(char **tab, int (*f)(char *)) {
  for (int i = 0; tab[i]; i++)
    if (f(tab[i]) != 0)
      return 1;

  return (0);
}
