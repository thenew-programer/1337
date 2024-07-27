#include <unistd.h>
char *dec_to_hex(int c, char *buffer) {
  int tmp, i = 0, k = 1, j;
  char hex_num[5];
  while (c != 0) {
    tmp = c % 16;

    if (tmp < 10)
      tmp += 48;
    else
      tmp += 87;
    hex_num[i++] = tmp;
    c /= 16;
  }
  buffer[0] = '0';
  for (j = i - 1; j >= 0; j--) {
    buffer[k] = hex_num[j];
    k++;
  }
  buffer[k] = '\0';
  return buffer;
}
void ft_putstr_non_printable(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 32 && str[i] <= 126)
      write(1, &str[i], 1);
    else {
      char hex[5];
      dec_to_hex((int)str[i], hex);
      write(1, "\\", 1);
      for (int j = 0; hex[j]; j++)
        write(1, &hex[j], 1);
    }
  }
  return;
}

int main() {
  char str[] = "\rHello\tworld\nhello\bhello\n";
  ft_putstr_non_printable(str);
}
