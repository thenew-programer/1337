char *ft_strlowcase(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 32;
  }
  return str;
}
int main() {
  char str[] = "YOUSSEF BOURYAL";
  ft_strlowcase(str);
  printf("%s\n", str);
}
