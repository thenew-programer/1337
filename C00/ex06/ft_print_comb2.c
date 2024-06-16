#include "../include.h"

void ft_putchar(char);
void display(int n) {
  if (n > 9) {
    char first = (n / 10) + 48;
    char second = (n % 10) + 48;

    ft_putchar(first);
    ft_putchar(second);
  } else {
    ft_putchar('0');
    ft_putchar(n + 48);
  }
}

void ft_print_comb2(void) {
  for (char i = 0; i < 100; i++) {
    for (char j = i + 1; j < 100; j++) {
      display(i);
      ft_putchar(' ');
      display(j);
      if (i == 98 && j == 99)
        continue;
      ft_putchar(',');
      ft_putchar(' ');
    }
  }
}
int main() {
  ft_print_comb2();
  return (0);
}
