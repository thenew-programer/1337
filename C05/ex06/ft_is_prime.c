#define TRUE 1
#define FALSE 0

int ft_is_prime(int nb) {
  if (nb == 0 || nb == 1)
    return FALSE;
  if (nb == 2)
    return TRUE;

  int dividors = 0;
  for (int i = 2; i < nb; i++)
    if (nb % i == 0)
      ++dividors;

  if (dividors > 0)
    return FALSE;
  return TRUE;
}

int main() {
  printf("is %d a prime number: %s\n", 7, ft_is_prime(7) ? "Yes" : "NO");
}
