#include <unistd.h>

void ft_print_comb(void) {
	int hello;
	for (int i = '0'; i <= '9'; i++) {
		for (int j = i + 1; j <= '9'; j++) {
			for (int k = j + 1; k <= '9'; k++) {
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if (i != '7')
					write(1, ", ", 2);
			}
		}
	}
}

int main() {
	ft_print_comb();
	write(1, "\n", 1);
}
