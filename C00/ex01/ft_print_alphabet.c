#include <unistd.h>

void ft_print_alphabet(void) {
				for (char c = 'a'; c <= 'z'; c++) {
								write(1, &c, 1);
				}
}

int main() {
				ft_print_alphabet();
				write(1, "\n", 1);
}
