#include <unistd.h>
#define MAX_SIZE 1000
#define EQUAL 0

/* Prototypes */
void ft_putstr(char *str);
char *ft_strcpy(char des[MAX_SIZE], char *src);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
char **ft_sort_params(char **params, char buffer[MAX_SIZE][MAX_SIZE], int len);

/* Main function*/
int main(int argc, char **argv) {
  if (argc <= 1)
    return -1;
  char buffer[MAX_SIZE][MAX_SIZE];
  ft_sort_params(argv, buffer, argc);
  for (int i = 0; i < argc - 1; i++) {
    ft_putstr(buffer[i]);
    write(1, "\n", 1);
  }
  return 0;
}

/* print a string*/
void ft_putstr(char *str) {
  for (int i = 0; str[i]; i++)
    write(1, &str[i], 1);
}

/* copy the string from src to dest*/
char *ft_strcpy(char dest[MAX_SIZE], char *src) {
  int i;
  for (i = 0; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

/* return the length of a string*/
int ft_strlen(char *str) {
  int i;
  for (i = 0; str[i]; i++) {
  }
  return i;
}

/* Compare to see if 2 strings are equal or not*/
int ft_strcmp(char *s1, char *s2) {
  int s1_len = ft_strlen(s1);
  int s2_len = ft_strlen(s2);
  int len = s1_len > s2_len ? s2_len : s1_len;
  for (int i = 0; i < len; i++) {
    if (s1[i] != s2[i])
      return (int)(s1[i] - s2[i]);
  }
  return 0;
}

/* sort argvs*/
char **ft_sort_params(char **params, char buffer[MAX_SIZE][MAX_SIZE], int len) {
  int i, j;
  for (i = 1; i < len; i++) {
    ft_strcpy(buffer[i - 1], params[i]);
  }
  buffer[i][0] = '\0';

  for (i = 0; i < len - 1; i++) {
    for (j = 0; j < len - 1; j++) {
      if (i == j)
        continue;
      if (ft_strcmp(buffer[i], buffer[j]) < EQUAL) {
        char tmp[MAX_SIZE];
        ft_strcpy(tmp, buffer[i]);
        ft_strcpy(buffer[i], buffer[j]);
        ft_strcpy(buffer[j], tmp);
      }
    }
  }
  return (char **)buffer;
}
