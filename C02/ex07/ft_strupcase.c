char *ft_strupcase(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] -= 32;
  }
  return str;
}

int main() {
  char str[] = "hello world";
  ft_strupcase(str);
  printf("%s\n", str);
}
