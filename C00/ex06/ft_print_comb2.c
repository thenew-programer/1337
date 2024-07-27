#include <unistd.h>

void ft_print_comb2(void) {
	for (int i = '0'; i <= '9'; i++) {
		for (int j = '0'; j <= '9'; j++) {
			for (int k = i; k <= '9'; k++) {
				for (int l = j + 1; l <= '9'; l++) {
					write(1, &i, 1);
					write(1, &j, 1);
					write(1, " ", 1);
					write(1, &k, 1);
					write(1, &l, 1);
					if (i == '9' && j == '8')
						continue;
					write(1, ", ", 2);

				}
			}

		}
	}
}

int main() {
	ft_print_comb2();
	write(1, "\n", 1);
}
