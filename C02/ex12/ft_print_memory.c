#include <unistd.h>

/*
 * Create a function that displays the memory area onscreen.
 * The display of this memory area should be split into three
 * "columns" separated by a space :
 *    - The hexadecimal address of the first line’s first character followed by
       a ’:’.
 *    - The content in hexadecimal with a space each 2 characters and should be
        padded with spaces if needed (see the example below).
 *    - The content in printable characters.
 * Constraints:
 *            - If a character is non-printable, it’ll be replaced by a dot.
 *            - Each line should handle sixteen characters.
 *            - If size equals to 0, nothing should be displayed.
 * Example:
 *          000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour
 les amin 000000010a161f50: 6368 6573 090a 0963 2020 6573 7420 666f ches...c est
 fo 000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on
            000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire
 avec. 000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a
 ..print_memory.. 000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 ..lol.lol. .
 */

/* data types*/
typedef unsigned char byte_t;
typedef unsigned int uint;

/* Prototypes*/
void ft_print(char *str);
void ft_println(char *str, uint size);
char *ft_convert_addr_to_hex(byte_t *addr, char *buffer);
char *ft_convert_int_to_hex(byte_t c, char *buffer);
void *ft_print_memory(void *addr, uint size);
void ft_process_subchunk(byte_t *addr, uint size);

/* Actual Code */

int main() {
  char str[] =
      "Bonjour les aminches\r\r\rc est fo u\ttout\tce qu on peut faire "
      "avec\b\b\bprint_memory\n\n\r\rlol.lol\n \n";

  ft_print_memory(str, sizeof(str) - 1);
}

/* Print function*/
void ft_print(char *str) {
  for (int i = 0; str[i]; i++) {
    char c = str[i];
    if (c >= 32 && c <= 126)
      write(1, &str[i], 1);
    else
      write(1, ".", 1);
  }
}
/* Print function with new line*/
void ft_println(char *str, uint size) {
  for (int i = 0; i < size; i++) {
    char c = str[i];
    if (c >= 32 && c <= 126)
      write(1, &str[i], 1);
    else
      write(1, ".", 1);
  }
  write(1, "\n", 1);
}

/* Convert addr to hex string*/
char *ft_convert_addr_to_hex(byte_t *addr, char *buffer) {
  char hex_digits[] = "0123456789abcdef";
  int buf_index = 0;

  for (int i = sizeof(void *) - 1; i >= 0; i--) {
    buffer[buf_index++] = hex_digits[(addr[i] >> 4) & 0xF];
    buffer[buf_index++] = hex_digits[addr[i] & 0xF];
  }
  buffer[buf_index] = '\0';
  return buffer;
}

/* Convert int to hex as a string*/
char *ft_convert_int_to_hex(unsigned char c, char *buffer) {
  int tmp, j, i = 0, k = 0;
  char hex_num[5];
  while (c != 0) {
    tmp = c % 16;

    if (tmp < 10)
      tmp += 48;
    else
      tmp += 87;
    hex_num[i++] = tmp;
    c /= 16;
  }
  if (i == 1) {
    buffer[k++] = '0';
  }
  for (j = i - 1; j >= 0; j--) {
    buffer[k] = hex_num[j];
    k++;
  }
  buffer[k] = '\0';
  return buffer;
}

/* ft_print_memory function*/
void *ft_print_memory(void *addr, uint size) {
  if (size == 0)
    return addr;

  int iterations = size / 16;
  int remainder = size % 16;

  for (int i = 0; i < iterations; i++) {
    ft_process_subchunk(addr + i * 16, 16);
  }

  if (remainder > 0) {
    ft_process_subchunk(addr + iterations * 16, remainder);
  }
  return addr;
}

/* function to process each sub section of the pointer*/
void ft_process_subchunk(byte_t *addr, uint size) {
  char buffer[20];
  int i;

  ft_convert_addr_to_hex(addr, buffer);
  ft_print(buffer);
  write(1, ": ", 2);

  // content in hex part
  for (i = 0; i < size; i++) {
    ft_convert_int_to_hex(addr[i], buffer);
    ft_print(buffer);
    if (i % 2 != 0)
      write(1, " ", 1);
  }

  // content printing part
  for (; i < 16; i++) {
    write(1, "  ", 2);
    if (i % 2 != 0)
      write(1, " ", 1);
  }
  ft_println((char *)addr, size);
}
