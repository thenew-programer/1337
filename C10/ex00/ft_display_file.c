#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd;
    char c;
    char *clang;

    if (argc < 2)
    {
	write(2, "File name missing.\n", 19);
	return 1;
    }
    else if (argc > 2)
    {
	write(2, "Too many arguments.\n", 20);
	return 1;
    }

    fd = open(argv[1], 00);
    if (fd < 0)
    {
	write(2, "Cannot read file.\n", 18);
	return 1;
    }

    while (read(fd, &c, 1) == 1)
	write(1, &c, 1);
    close(fd);
    return (0);
}
