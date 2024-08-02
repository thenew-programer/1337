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
int ft_find_next_prime(int nb) {
  if (nb == 0 || nb == 1 || nb == 2)
    return 2;
  while (TRUE) {
    if (nb % 2 == 0) // if nb is even it is not prime
      nb++;
    else if (ft_is_prime(nb)) // if ft_is_prime returns it
      return nb;
    else
      nb += 2; // nb + 2 to reduce checking the next even number
  }
}

int main() {
  printf("The next prime number after %d -> %d\n", 8, ft_find_next_prime(8));
  printf("The next prime number after %d -> %d\n", 0, ft_find_next_prime(0));
  printf("The next prime number after %d -> %d\n", 1, ft_find_next_prime(1));
  printf("The next prime number after %d -> %d\n", 2, ft_find_next_prime(2));
  printf("The next prime number after %d -> %d\n", 3, ft_find_next_prime(3));
  printf("The next prime number after %d -> %d\n", 4, ft_find_next_prime(4));
  printf("The next prime number after %d -> %d\n", 5, ft_find_next_prime(5));
  printf("The next prime number after %d -> %d\n", 11, ft_find_next_prime(11));
}
