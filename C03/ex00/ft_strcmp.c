#include <unistd.h>
/*
       The  strcmp() function compares the two strings s1 and s2.  The locale is
   not taken into account (for a locale-aware comparison, see strcoll(3)).  The
   comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as
   follows:

       •  0, if the s1 and s2 are equal;

       •  a negative value if s1 is less than s2;

       •  a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only the first (at
   most) n bytes of s1 and s2.
*/
int ft_strcmp(char *s1, char *s2) {
  for (int i = 0; s1[i] || s2[i]; i++) {
    if (s1[i] != s2[i])
      return (int)(s1[i] - s2[i]);
  }
  return 0;
}

int main() {
  char s1[] = "Hellow";
  char s2[] = "Helloa";
  int result = ft_strcmp(s1, s2);
  if (result == 0)
    write(1, "EQUAL\n", 6);
  else if (result > 0)
    write(1, "s1 is bigger than s2\n", 21);
  else
    write(1, "s2 is bigger than s1\n", 21);
}
