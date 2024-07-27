#include <stdio.h>

/*Prototypes*/
int is_base_valid(char *base);
int ft_atoi_base(char *str, char *base);
int atoi_base(char *str, char *base);
char *get_numbers_from_str(char *str, char *buffer, char *base);
char *get_signs_from_str(char *str, char *buffer);
int convert_str_to_int(char *str, char *base);
int ft_strlen(char *str);
int is_c_in_base(char c, char *base);
int get_index(char value, char *arr);

int main(int argc, char **argv) {
  char *base;
  char *str;

  if (argc != 3) {
    printf("Usage: <number> <base>\n");
    return (-1);
  }

  base = argv[2];
  str = argv[1];
  int number = ft_atoi_base(str, base);
  printf("<%s> base <%s> ---> %d\n", str, base, number);
  return (0);
}

int is_base_valid(char *base) {
  int i, j;

  if (!base)
    return 0;
  for (i = 0; base[i]; i++) {
    char c = base[i];
    if (c == '+' || c == '-' || c == ' ' || c == '\t' || c == '\n')
      return i * -1;
    for (j = i + 1; base[j]; j++) {
      if (c == base[j])
        return i * -1;
    }
  }
  return i;
}

char *get_numbers_from_str(char *str, char *buffer, char *base) {
  int buf_index = 0, i;

  while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '\t' ||
         str[i] == '\n')
    i++;

  for (; str[i]; i++) {
    if (is_c_in_base(str[i], base))
      buffer[buf_index++] = str[i];
    else
      break;
  }
  buffer[buf_index] = '\0';
  return buffer;
}

char *get_signs_from_str(char *str, char *buffer) {
  int buf_index = 0;
  int i = 0;

  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    i++;

  for (; str[i]; i++) {
    if (str[i] == '-')
      buffer[buf_index++] = str[i];
    else if (str[i] == '+')
      continue;
    else
      break;
  }
  buffer[buf_index] = '\0';
  return buffer;
}

int convert_str_to_int(char *str, char *base) {
  int nbr = 0;
  int base_type = ft_strlen(base);

  for (int i = 0; str[i]; i++) {
    nbr *= base_type;
    int index = get_index(str[i], base);
    if (index < 0)
      return 0;
    nbr += index;
  }
  return nbr;
}

int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

int is_c_in_base(char c, char *base) {
  for (int i = 0; base[i]; i++)
    if (c == base[i])
      return 1;

  return 0;
}

int get_index(char value, char *arr) {
  for (int i = 0; arr[i]; i++) {
    if (arr[i] == value)
      return i;
  };
  return -1;
}

int atoi_base(char *str, char *base) {
  char numbers[100];
  char minus_signs[100];
  int nbr;
  get_signs_from_str(str, minus_signs);
  get_numbers_from_str(str, numbers, base);
  nbr = convert_str_to_int(numbers, base);
  int minus_count = ft_strlen(minus_signs);
  return minus_count % 2 ? nbr * -1 : nbr;
}

int ft_atoi_base(char *str, char *base) {
  int base_type = is_base_valid(base);

  if (base_type < 2)
    return 0;
  else
    return atoi_base(str, base);
}
