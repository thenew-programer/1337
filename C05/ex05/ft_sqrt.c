int ft_sqrt(int nb) {
  if (nb <= 0)
    return 0;
  for (int i = 0; i <= nb; i++) {
    if (i * i == nb)
      return i;
  }
  return 0;
}

int main() {
  printf("the square root of %d is %d\n", 4, ft_sqrt(4));
  printf("the square root of %d is %d\n", 16, ft_sqrt(16));
  printf("the square root of %d is %d\n", 32, ft_sqrt(32));
  printf("the square root of %d is %d\n", 64, ft_sqrt(64));
}
