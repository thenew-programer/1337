unsigned int ft_strlcpy(char *dest, char *src, unsigned int size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return (unsigned int)sizeof(src);
}

int main() {
  char str1[20] = "Youssef Bouryal_001";
  char str2[10];
  ft_strlcpy(str2, str1, 10);
  printf("%s\n", str2);
  return (0);
}
