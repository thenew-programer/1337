int is_lowercase(char c) {
  if (c >= 'a' && c <= 'z')
    return 1;
  return 0;
}
char *ft_strcapitalize(char *str) {
  if (is_lowercase(str[0])) {
    str[0] -= 32;
  }
  for (int i = 1; str[i]; i++) {
    if (((str[i - 1] == ' ') || (str[i - 1] == '+')) && is_lowercase(str[i]))
      str[i] -= 32;
    else
      continue;
  }
  return str;
}

int main(void) {
  char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
  ft_strcapitalize(str);
  printf("%s\n", str);
  return (0);
}
