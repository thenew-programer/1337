#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Prototypes*/
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

/* ft_atoi_base functions */
long long ft_atoi_base(char *nbr, char *base);
char *get_numbers(char *nbr, char *base);
int get_signs(char *nbr);
long long _convert_str(char *nbr, char *base);
char *_convert_int_to_str(int nbr, char *base, int is_negative);

/* ft_convnbr_base functions */
char *ft_convnbr_base(int nbr, char *base);

/* Utils */
int is_base_valid(char *base);
int ft_strlen(char *str);
int get_index(char value, char *str);
char *ft_rev_str(char *str, int size);
int ft_nbrlen(int nbr, int base);

/* Main function for testing*/
int main() {
  char base10[] = "0123456789";
  char base16[] = "0123456789ABCDEF";
  char base8[] = "01234567";
  char base2[] = "01";
  char str[] = " \t\n --++42x7891234567879asdweg";
  char *nbr = ft_convert_base(str, base10, base16);
  printf("(%s) in base (%s) = (%s) in base (%s)\n", str, base10, nbr, base16);
  free(nbr);
  return 0;
}

/* START - Utils*/
/**
 * ft_nbrlen - calculate how many digits in the given number
 *
 * @nbr (int): the number
 * @base (int): the base of the number
 *
 * Return: number of digits
 */
int ft_nbrlen(int nbr, int base) {
  int i;

  if (base < 2)
    return 0;
  i = 0;
  while (nbr) {
    nbr /= base;
    i++;
  }
  return i;
}
/**
 * is_base_valid - check whether a base string is valid
 * or not. A base is valid if there is no `+`, `-` or
 * whitespaces in it, and if there is not duplicates.
 *
 * @base: the pointer to the base string
 *
 * Return: length of the base if the base is valid
 * 			negative number otherwise
 */
int is_base_valid(char *base) {
  int i;

  if (!base)
    return 0;
  for (i = 0; base[i]; i++) {
    // if base has `+`, `-` or whitespaces
    if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || base[i] == '\t' ||
        base[i] == '\n' || base[i] == '\r' || base[i] == '\f' ||
        base[i] == '\v')
      return i * -1;
    // if base has a duplicate character
    for (int j = 0; base[j]; j++) {
      if (i == j)
        continue;
      if (base[i] == base[j])
        return i * -1;
    }
  }
  return i;
}

/**
 * ft_strlen - returns the length of a null terminated string
 *
 * @str: the pointer to the string
 *
 * Return: length of the string of type int
 */
int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

/**
 * get_index - returns the index of a char from a string
 *
 * @value: the char we're looking for
 *
 * Return: index if the char is found
 * 			-1 otherwise
 */
int get_index(char value, char *str) {
  int i = 0;

  for (i = 0; str[i]; i++) {
    if (str[i] == value)
      return i;
  }
  return -1;
}

/**
 * ft_rev_str - reverse a string
 *
 * @str: pointer to string to be reversed
 * @size: length of the string
 *
 * Return: pointer to the string
 */
char *ft_rev_str(char *str, int size) {
  int i, j;

  for (i = 0, j = size - 1; i < j; i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
  return str;
}
/* END - Utils*/

/* START - ft_atoi_base */

char *get_numbers(char *nbr, char *base) {
  char *numbers;
  int len, i, buf_index;

  len = ft_strlen(nbr);
  buf_index = 0, i = 0;
  numbers = (char *)malloc(sizeof(char) * len);
  if (!numbers)
    return NULL;

  while (nbr[i] == '-' || nbr[i] == '+' || nbr[i] == ' ' || nbr[i] == '\t' ||
         nbr[i] == '\n' || nbr[i] == '\r' || nbr[i] == '\f' || nbr[i] == '\v')
    i++;

  for (; i < len; i++) {
    int idx = get_index(nbr[i], base);
    if (idx < 0)
      break;
    numbers[buf_index++] = nbr[i];
  }
  numbers[buf_index] = '\0';
  return numbers;
}

/**
 * get_signs - return the number of minus signs in the string nbr
 * to decide whether the nbr is positive or negative
 *
 * @nbr: pointer to the string nbr
 *
 * Return: number of minus signs
 */
int get_signs(char *nbr) {
  int signs_count, i;

  signs_count = 0, i = 0;

  while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\r' ||
         nbr[i] == '\f' || nbr[i] == '\v')
    i++;

  for (; nbr[i]; i++) {
    if (nbr[i] == '-')
      signs_count++;
    else if (nbr[i] == '+')
      continue;
    else
      break;
  }
  return signs_count;
}

/**
 * _convert_str -  convert string nbr of base to int
 *
 * @nbr: pointer to nbr string
 * @base: pointer to base of nbr string
 *
 * Return: int of nbr string or 0
 */
long long _convert_str(char *nbr, char *base) {
  int base_type;
  long long result;

  base_type = ft_strlen(base);
  result = 0;

  for (int i = 0; nbr[i]; i++) {
    result *= base_type;
    int idx = get_index(nbr[i], base);
    if (idx < 0)
      return 0;
    result += idx;
  }
  return result;
}

/**
 * ft_atoi_base - convert a nbr of string type to base10 integer type
 *
 * @nbr: pointer to the number
 * @base: pointer to the base of the number
 *
 * Return: nbr if nbr and base is valid
 * 			0 otherwise
 */
long long ft_atoi_base(char *nbr, char *base) {
  char *numbers;
  int minus_count;
  long long result;

  // get the valid numbers of the string nbr
  numbers = get_numbers(nbr, base);
  if (!numbers)
    return 0;
  // get minus signs from the string nbr
  minus_count = get_signs(nbr);
  // convert the string nbr to int
  result = _convert_str(numbers, base);

  free(numbers);

  return minus_count % 2 ? result * -1 : result;
}
/* END - ft_atoi_base */

/* START - ft_convnbr_base */
/**
 * _convert_int_to_str - helper function for ft_convnbr_base
 *
 * @nbr:
 * @base:
 * @is_negative: flag telling if the number given is negative or not
 *
 * Return: pointer to the converted number
 */
char *_convert_int_to_str(int nbr, char *base, int is_negative) {
  char *buffer;
  int buf_index, base_type, nbr_len;

  buf_index = 0;
  base_type = ft_strlen(base);
  nbr_len = ft_nbrlen(nbr, base_type);
  buffer = (char *)malloc(sizeof(char) * nbr_len);
  if (!buffer)
    return NULL;

  while (nbr) {
    buffer[buf_index++] = base[(nbr % base_type)];
    nbr /= base_type;
  }
  if (is_negative)
    buffer[buf_index++] = '-';
  buffer[buf_index] = '\0';
  ft_rev_str(buffer, buf_index);
  return buffer;
}
/**
 * ft_convnbr_base - convert a nbr of base 10 to number of the base given
 *
 * @nbr: nbr to be converted
 * @base: pointer to the base to convert the number to
 *
 * Return: pointer to converted number
 * 			NULL if an error occurs
 */
char *ft_convnbr_base(int nbr, char *base) {
  char *result;
  int is_negative = nbr < 0 ? 1 : 0;
  if (is_negative)
    nbr *= -1;
  result = _convert_int_to_str(nbr, base, is_negative);
  return result;
}
/* END - ft_convnbr_base */

/* START - ft_convert_base */
/**
 * ft_convert_base - returns the result of the conversion of the string nbr from
 *	a base base_from to a base base_to.
 *	@nbr: pointer to nbr string
 *	@base_from: pointer to initial base of the string nbr
 *	@base_to: pointer to the base which the nbr will be converted to
 *
 *	Return: pointer to the converted nbr (needs to be freed using free())
 */
char *ft_convert_base(char *nbr, char *base_from, char *base_to) {
  // check if base is valid
  if (is_base_valid(base_from) < 2 || is_base_valid(base_to) < 2)
    return NULL;
  // convert number from base_from to int of base 10
  long long converted_nbr = ft_atoi_base(nbr, base_from);

  // check for overflow
  if (converted_nbr > INT_MAX || converted_nbr < INT_MIN)
    return NULL;

  // convert int of base 10 to str of base_to
  char *base_to_nbr = ft_convnbr_base((int)converted_nbr, base_to);
  return base_to_nbr;
}
/* END - ft_convert_base */
