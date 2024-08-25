// #include "ft_stock_str.h"
// #include <unistd.h>
//
// struct s_stock_str {
//   int size;
//   char *str;
//   char *copy;
// };

static void ft_putstr(char *);
static void ft_putnbr(int);
static char *ft_rev_str(char *, int);
void ft_show_tab(struct s_stock_str *);
// struct s_stock_str *ft_strs_to_tab(int, char **);

// int main() {
//   char *strs[] = {
//       "HEllo", "WORLD", "Youssef", "BOuryal", "HAmid", "SLMlm",
//   };
//   int size = 6;
//   struct s_stock_str *stock;
//   stock = ft_strs_to_tab(size, strs);
//   ft_show_tab(stock);
// }

static char *ft_rev_str(char *str, int size) {
  int i;
  int j;

  for (i = 0, j = size - 1; i < j; i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
  return str;
}

static void ft_putnbr(int nbr) {
  char buffer[20];
  int buf_index;

  if (nbr == 0) {
    write(1, "0", 1);
    return;
  }

  buf_index = 0;
  while (nbr) {
    buffer[buf_index++] = (nbr % 10) + 48;
    nbr /= 10;
  }
  buffer[buf_index] = '\0';
  ft_rev_str(buffer, buf_index);

  ft_putstr(buffer);
}

static void ft_putstr(char *str) {
  for (int i = 0; str[i]; i++)
    write(1, &str[i], 1);
}

void ft_show_tab(struct s_stock_str *par) {
  if (!par)
    return;

  for (int i = 0; par[i].str; i++) {
    ft_putstr(par[i].str);
    write(1, "\n", 1);
    ft_putnbr(par[i].size);
    write(1, "\n", 1);
    ft_putstr(par[i].copy);
    write(1, "\n", 1);
  }
}
