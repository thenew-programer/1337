#include <unistd.h>

void ft_putnbr(int n) {
	char buffer[100], i = 0;
	if (n == 0) {
		write(1, "0", 1);
		return;
	}
	while (n != 0) {
		int tmp = (n % 10) + 48;
		n /= 10;
		buffer[i] = tmp;
		i++;
		// write(1, &tmp, 1);
	}
	while (i >= 0) {
		write(1, &buffer[i], 1);
		i--;
	}
}

int main(void) {
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(1337);
	write(1, "\n", 1);
	ft_putnbr(1000);
	write(1, "\n", 1);
	ft_putnbr(000000);
	write(1, "\n", 1);
}
