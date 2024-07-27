#include <unistd.h>

int ft_strncmp(char *s1, char *s2, unsigned int n) {
  for (int i = 0; (s1[i] || s2[i]) && i < n; i++) {
    if (s1[i] != s2[i])
      return (int)(s1[i] - s2[i]);
  }
  return 0;
}

int main() {
  char s1[] = "Hellow";
  char s2[] = "Hellowwwwww";
  int result = ft_strncmp(s1, s2, 7);
  if (result == 0)
    write(1, "EQUAL\n", 6);
  else if (result > 0)
    write(1, "s1 is bigger than s2\n", 21);
  else
    write(1, "s2 is bigger than s1\n", 21);
}
