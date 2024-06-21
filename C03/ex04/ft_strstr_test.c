#include <stdio.h>
#include "ft_strstr.h"

int main() {
  char haystack[] = "geeksforgeeks";
  char needle[] = "for";
  char * found_str;

  found_str = ft_strstr(haystack, needle);
  printf("Needle is present -> %s\n", !found_str ? "False" : found_str);
}
