void ft_foreach(int *tab, int length, void (*f)(int)) {
  for (int i = 0; i < length; i++)
    f(tab[i]);
}
