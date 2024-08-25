#include "do-op.h"

/*Prototypes*/
static char *get_signs_from_str(char *str, char *buffer);
static int convert_str_to_int(char *numbers);

/* return the valid numbers from the string*/
char *get_numbers_from_str(char *str, char *buffer) {
  int buf_index = 0, i;

  i = 0;
  while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '\t' ||
         str[i] == '\n')
    i++;

  for (; str[i]; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      buffer[buf_index++] = str[i];
    else
      break;
  }
  buffer[buf_index] = '\0';
  return buffer;
}

/* Return all minus signs before numbers*/
static char *get_signs_from_str(char *str, char *buffer) {
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

/* return the length of a str*/
static int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

/* convert string of number to in*/
static int convert_str_to_int(char *str) {
  int nbr = 0;

  for (int i = 0; str[i]; i++) {
    nbr *= 10;
    nbr += (int)(str[i] - '0');
  }
  return nbr;
}

int ft_atoi(char *str) {
  char numbers[100];
  char minus_signs[100];
  int nbr;
  get_numbers_from_str(str, numbers);
  get_signs_from_str(str, minus_signs);
  nbr = convert_str_to_int(numbers);
  int minus_count = ft_strlen(minus_signs);
  return minus_count % 2 ? nbr * -1 : nbr;
}
