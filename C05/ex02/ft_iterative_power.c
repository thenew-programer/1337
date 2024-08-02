int ft_iterative_power(int nb, int power) {
  int result = 1;
  for (int i = 1; i <= power; i++) {
    result *= nb;
  }
  return result;
}

int main() {
  printf("2 ^ 8 = %d\n", ft_iterative_power(2, 8));
  return 0;
}
