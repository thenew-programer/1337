#include "../include.h"

int main() {
  printf("\n=======================================\n");
  printf("TEST of ft_ft()\n");
  int nbr = 0;
  printf("nbr before mutating: %d\n", nbr);
  ft_ft(&nbr);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_div_mod()\n");
  int div, mod;
  ft_div_mod(10, 3, &div, &mod);
  printf("10 / 3 = %d, remainder = %d\n", div, mod);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_ultimate_div_mod()\n");
  int a = 10;
  int b = 3;
  ft_ultimate_div_mod(&a, &b);
  printf("a / b = %d, remainder = %d\n", a, b);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_strlen()\n");
  char *str = "Hello world";
  printf(
      "str len using strlen() func: %d\nstr len using ft_strlen() func: %d\n",
      strlen((const char *)str), ft_strlen(str));
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_putstr()\n");
  char *str = "Hello world\n";
  ft_putstr(str);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_swap()\n");
  int a = 10;
  int b = 11;
  printf("a = %d\nb = %d\n", a, b);
  ft_swap(&a, &b);
  printf("SWAP\na = %d\nb = %d\n", a, b);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("TEST of ft_rev_int_tab()\n");
  int tab[] = {10, 11, 12, 13, 14, 15, 16};
  for (int i = 0; i < 7; i++)
    printf("[i] = %d\n", tab[i]);
  ft_rev_int_tab(tab, 7);
  printf("\n\nREVERSE ARRAY\n\n");
  for (int i = 0; i < 7; i++)
    printf("[%d] = %d\n", i, tab[i]);
  printf("\n=======================================\n");
  return (0);
}
