#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * ft_puterr - print errors to stderr returned from strerror
 *
 * @filename: pointer to the filename of which the error occured
 * @err: pointer to err string
 *
 * Return: nothing
 */
void ft_puterr(char *err) {
  int i;

  if (!err) {
    return;
  }

  i = 0;
  while (err[i])
    write(2, &err[i++], 1);
}

/**
 * ft_display - print content of a fd to stdout
 *
 * @fd: fd to print from
 *
 * Return: number of bytes printed
 *         -1 on error
 */
int ft_display(int fd) {
  int count;
  char c;

  if (fd < 0)
    return -1;

  count = 0;
  while (read(fd, &c, 1) == 1) {
    write(1, &c, 1);
    count++;
  }

  return count;
}

/**
 * ft_cat - prints a the content of a file to stdout
 *
 * @filename: file to be printed
 *
 * Return: number of characters printed
 *        -1 on error
 */
int ft_cat(char *filename) {
  int count;
  int fd;

  if (!filename) {
    count = ft_display(0);
    return count;
  }

  fd = open(filename, O_RDONLY);
  if (fd < 0) {
    ft_puterr("ft_cat: ");
    ft_puterr(filename);
    ft_puterr(": No Such File or Directory\n");
    return -1;
  }

  count = ft_display(fd);
  close(fd);
  return count;
}

int main(int argc, char **argv) {
  int i;
  int rt;

  if (argc < 2) {
    rt = ft_cat(0);
    if (rt < 0)
      return (1);
    return (0);
  }
  i = 1;
  rt = 0;
  while (i < argc) {
    if (ft_cat(argv[i++]) < 0)
      rt = 1;
  }
  return rt;
}
