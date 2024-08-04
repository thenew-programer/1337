// #include "ft_stock_str.h"
// #include <stdio.h>
// #include <stdlib.h>
//
// struct s_stock_str {
//   int size;
//   char *str;
//   char *copy;
// };

static int ft_strlen(char *str) {
  int i;

  for (i = 0; str[i]; i++) {
  }
  return (i);
}

static char *ft_strcpy(char *str) {
  char *buffer;
  int size, i;

  size = ft_strlen(str);
  buffer = (char *)malloc(sizeof(char) * (size + 1));
  if (!buffer)
    return NULL;

  for (i = 0; str[i]; i++) {
    buffer[i] = str[i];
  }
  buffer[i] = '\0';
  return buffer;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av) {
  struct s_stock_str *stock;
  int i;

  stock = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
  if (!stock)
    return NULL;
  for (i = 0; i < ac; i++) {
    stock[i].size = ft_strlen(av[i]);
    stock[i].str = ft_strcpy(av[i]);
    stock[i].copy = ft_strcpy(av[i]);
  }
  stock[i].size = 0;
  stock[i].str = NULL;
  stock[i].copy = NULL;
  return (stock);
}
//
// void print_stock(struct s_stock_str *stock) {
//   if (!stock)
//     return;
//
//   for (int i = 0; stock[i].str; i++) {
//     printf("[%d]\n\tstr -> %s\n\tcopy -> %s\n\tsize -> %d\n", i,
//     stock[i].str,
//            stock[i].copy, stock[i].size);
//   }
// }
//
// void ft_free_stock(struct s_stock_str *ptr) {
//   for (int i = 0; ptr[i].str; i++) {
//     free(ptr[i].str);
//     free(ptr[i].copy);
//   }
//   free(ptr);
// }
//
// int main() {
//   char *strs[] = {"HELlo", "WORLD", "Youssef", "HAMID", "SLMLM"};
//   int size = 5;
//   struct s_stock_str *stock = ft_strs_to_tab(size, strs);
//   print_stock(stock);
//   ft_free_stock(stock);
// }
