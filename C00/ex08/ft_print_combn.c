#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_display(char* min_tab, char* max_tab, int n) {
	int i = 0;

	while (i < n) {
		ft_putchar(min_tab[i++]);
	}
	if (min_tab[0] != max_tab[0]) {
		write(1, ", ", 2);
	}
}

void ft_print_combn(int n) {
	if (n <= 0 || n >= 10) return;

	char min_tab[n];
	char max_tab[n];
	int i;

	/* Fill the tables */
	while (i < n) {
		min_tab[i] = '0' + i; /* Min value each number can have*/
		max_tab[i++] = (10 - n) + i + '0'; /*Max value each number can have*/
	}


	/*printing and incrementing*/
	while (min_tab[0] != max_tab[0]) {
		i = n - 1;
		ft_display(min_tab, max_tab, n);

		while (min_tab[i] == max_tab[i]) i--;

		int tmp = ++min_tab[i];

		while (i < n)
			min_tab[++i] = ++tmp;
	}

	ft_display(min_tab, max_tab, n);
}

int main() {
	ft_print_combn(2);
	write(1, "\n", 1);
	ft_print_combn(7);
	write(1, "\n", 1);
}
