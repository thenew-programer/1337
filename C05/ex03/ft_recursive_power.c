int ft_recursive_power(int nb, int power) {
  if (power == 0)
    return 1;
  return nb * ft_recursive_power(nb, power - 1);
}

int main() {
  printf("2 ^ 8 = %d\n", ft_recursive_power(2, 8));
  return 0;
}
