int ft_iterative_fibonacci(int index) {
  int fibs[index + 2];
  fibs[0] = 0;
  fibs[1] = 1;
  for (int i = 2; i <= index + 1; i++) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
  }
  return fibs[index + 1];
}
int ft_fibonacci(int index) {
  if (index < 0)
    return -1;
  if (index <= 2)
    return index;
  return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int main() {
  printf("fibo at index 8 ==> %d\n", ft_fibonacci(8));
  printf("fibo at index 8 ==> %d\n", ft_iterative_fibonacci(8));
  return (0);
}
