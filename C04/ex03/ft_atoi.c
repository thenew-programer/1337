#include <stdio.h>
/*
 * Write a function that converts the initial portion of the string pointed by
str to its int representation • The string can start with an arbitray amount of
white space (as determined by isspace(3))
 * • The string can be followed by an arbitrary amount of + and - signs, - sign
        will change the sign of the int returned based on the number of - is odd
                or even.
 * • Finally the string can be followed by any numbers of the base 10.
 * • Your function should read the string until the string stop following the
        rules and return the number found until now.
 * • You should not take care of overflow or underflow. result can be undefined
        in that case.
 * • Here’s an example of a program that prints the atoi return value:
 */

/*Prototypes*/
int ft_atoi(char *str);
char *get_numbers_from_str(char *str, char *buffer);
char *get_signs_from_str(char *str, char *buffer);
int convert_str_to_int(char *numbers);

/* Main function*/
int main() {
  char str[] = " w ---+--+1234ab567";
  printf("str -> %s\nnumber -> %d\n", str, ft_atoi(str));
  return (0);
}

/* return the valid numbers from the string*/
char *get_numbers_from_str(char *str, char *buffer) {
  int buf_index = 0, i;

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

/* return the length of a str*/
int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

/* convert string of number to in*/
int convert_str_to_int(char *str) {
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
