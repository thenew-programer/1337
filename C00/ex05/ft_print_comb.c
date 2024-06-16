#include "../include.h"

void ft_print_comb(void) {
  char tmp_i, tmp_j, tmp_k;
  for (char i = 0; i < 10; i++) {
    for (char j = i + 1; j < 10; j++) {
      for (char k = j + 1; k < 10; k++) {
        tmp_i = i + '0';
        tmp_j = j + '0';
        tmp_k = k + '0';
        write(1, &tmp_i, 1);
        write(1, &tmp_j, 1);
        write(1, &tmp_k, 1);
        if (i == 7 && j == 8 && k == 9)
          continue;
        write(1, ", ", 2);
      }
    }
  }
}
