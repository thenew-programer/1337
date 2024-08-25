#include <stdio.h>

typedef struct s_oper_func {
  char operator;
  int (*calc)(int, int);
} t_oper_func;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

int main(int argc, char *argv[]) {
  t_oper_func operators[] = {
      {'+', add}, {'-', sub}, {'*', mul}, {'/', div}, {'%', mod}, {'\0', NULL},
  };
  int a, b;
  char operator;
  printf("Enter first Number -> ");
  scanf("%d", &a);
  printf("\nEnter Second Number -> ");
  scanf("%d", &b);
  printf("\nEnter operator (+,-,*,/,\%) -> ");
  scanf(" %c", &operator);

  for (int i = 0; operators[i].operator; i++) {
    if (operator== operators[i].operator)
      printf("%d %c %d = %d\n", a, operator, b, operators[i].calc(a, b));
  }

  return (0);
}
