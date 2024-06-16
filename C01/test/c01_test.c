#include "../include.h"

int main() {
  /* declare variabls*/
  int nbr, div, mod, a, b;
  char *str;

  printf("\n=======================================\n");
  printf("\nTEST of ft_ft()\n\n");
  nbr = 0;
  printf("nbr before mutating: %d\n", nbr);
  ft_ft(&nbr);
  printf("nbr after mutating: %d\n", nbr);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_div_mod()\n\n");
  div, mod;
  ft_div_mod(10, 3, &div, &mod);
  printf("10 / 3 = %d, remainder = %d\n", div, mod);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_ultimate_div_mod()\n\n");
  a = 10;
  b = 3;
  ft_ultimate_div_mod(&a, &b);
  printf("a / b = %d, remainder = %d\n", a, b);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_strlen()\n\n");
  str = "Hello world";
  printf(
      "str len using strlen() func: %d\nstr len using ft_strlen() func: %d\n",
      strlen((const char *)str), ft_strlen(str));
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_putstr()\n\n");
  str = "Hello world\n";
  ft_putstr(str);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_swap()\n\n");
  a = 10;
  b = 11;
  printf("a = %d\nb = %d\n", a, b);
  ft_swap(&a, &b);
  printf("SWAP\na = %d\nb = %d\n", a, b);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_rev_int_tab()\n\n");
  int tab[] = {10, 11, 12, 13, 14, 15, 16};
  for (int i = 0; i < 7; i++)
    printf("[i] = %d\n", tab[i]);
  ft_rev_int_tab(tab, 7);
  printf("\n\nREVERSE ARRAY\n\n");
  for (int i = 0; i < 7; i++)
    printf("[%d] = %d\n", i, tab[i]);
  printf("\n=======================================\n");

  printf("\n=======================================\n");
  printf("\nTEST of ft_sort_int_tab()\n\n");
  int tabb[] = {23, 1, 33, 122, 43, 0, -1, 10};
  for (int i = 0; i < 7; i++)
    printf("[i] = %d\n", tabb[i]);
  ft_sort_int_tab(tabb, 7);
  printf("\n\nSORT ARRAY\n\n");
  for (int i = 0; i < 7; i++)
    printf("\n[%d] = %d\n", i, tabb[i]);
  printf("\n=======================================\n");
  return (0);
}
