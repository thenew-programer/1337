/*
* • Create a function that displays a number in a base system in the terminal.
* • This number is given in the shape of an int, and the radix in the shape of a
string of characters.
* • The base-system contains all useable symbols to display that number :
        * ◦ 0123456789 is the commonly used base system to represent decimal
numbers
        * ◦ 01 is a binary base system ;
        * ◦ 0123456789ABCDEF an hexadecimal base system ;
        *◦ poneyvif is an octal base system.
*• The function must handle negative numbers.
*• If there’s an invalid argument, nothing should be displayed. Examples of
invalid arguments : *◦ base is empty or size of 1; *◦ base contains the same
character twice ; *◦ base contains + or - ;
*/
#include <unistd.h>

/*Prototypes*/
void ft_putnbr_base(int nbr, char *base);
int is_base_valid(char *base);
char *putnbr_base(int nbr, char *base, char *buffer, int is_negative);
void ft_putstr(char *str);
char *ft_reverse_str(char *str, int size);
int ft_strlen(char *str);

int main() {
  char base10[] = "0123456789";
  char base16[] = "0123456789ABCDEF";
  char base8[] = "poneyvif";
  char base2[] = "01";
  char base10False[] = "0123-43i3";
  char base16False[] = "0123456-89ABCDEF";
  char base8False[] = "poneyvii";
  char base2False[] = "00";
  char *baseEmpty;

  // 42
  ft_putnbr_base(42, base2);
  write(1, "\n", 1);
  ft_putnbr_base(42, base8);
  write(1, "\n", 1);
  ft_putnbr_base(42, base10);
  write(1, "\n", 1);
  ft_putnbr_base(42, base16);
  write(1, "\n", 1);
  // 1337
  ft_putnbr_base(1337, base2);
  write(1, "\n", 1);
  ft_putnbr_base(1337, base8);
  write(1, "\n", 1);
  ft_putnbr_base(-1337, base10);
  write(1, "\n", 1);
  ft_putnbr_base(1337, base16);
  write(1, "\n", 1);
  return (0);
}

int is_base_valid(char *base) {
  int i, j;

  if (!base)
    return 0;
  for (i = 0; base[i]; i++) {
    char c = base[i];
    if (c == '+' || c == '-')
      return i * -1;
    for (j = i + 1; base[j]; j++) {
      if (c == base[j])
        return i * -1;
    }
  }
  return i;
}

char *putnbr_base(int nbr, char *base, char *buffer, int is_negative) {
  int i;
  int buf_index = 0;
  int base_type = ft_strlen(base);

  while (nbr) {
    buffer[buf_index++] = base[(nbr % base_type)];
    nbr /= base_type;
  }
  if (is_negative)
    buffer[buf_index++] = '-';
  buffer[buf_index] = '\0';
  ft_reverse_str(buffer, buf_index);
  return buffer;
}

void ft_putstr(char *str) {
  for (int i = 0; str[i]; i++)
    write(1, &str[i], 1);
}

char *ft_reverse_str(char *str, int size) {
  char *start = str;
  char *end = str + size - 1;
  while (start < end) {
    char tmp = *start;
    *start = *end;
    *end = tmp;
    start++;
    end--;
  }
  return str;
}

int ft_strlen(char *str) {
  int i;

  for (i = 0; str[i]; i++) {
  }
  return i;
}

void ft_putnbr_base(int nbr, char *base) {
  // for later use because we want the number positive
  int is_negative = nbr < 0 ? 1 : 0;
  char buffer[100];

  // turn the number positive;
  nbr = is_negative ? nbr * -1 : nbr;

  int base_type = is_base_valid(base);
  switch (base_type) {
  case 2:
    // convert number to base 2
    putnbr_base(nbr, base, buffer, is_negative);
    break;
  case 8:
    // convert number to base 8
    putnbr_base(nbr, base, buffer, is_negative);
    break;
  case 10:
    // convert number to base 10
    putnbr_base(nbr, base, buffer, is_negative);
    break;
  case 16:
    // convert number to base 16
    putnbr_base(nbr, base, buffer, is_negative);
    break;
  default:
    // base is invalid do nothing
    return;
  }
  ft_putstr(buffer);
}
