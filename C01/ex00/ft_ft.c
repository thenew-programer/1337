#include <stdio.h>

void ft_ft(int *nbr) {
				*nbr = 42;
}

int main() {
				int n = 10;
				printf("n = %d\n", n);
				ft_ft(&n);
				printf("After ft_ft:\n");
				printf("n = %d\n", n);
}
