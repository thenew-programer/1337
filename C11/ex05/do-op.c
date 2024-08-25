#include "do-op.h"
#include <unistd.h>

/* Prototypes */
static int Add(int a, int b);
static int Sub(int a, int b);
static int Mul(int a, int b);
static int Div(int a, int b);
static int Mod(int a, int b);
static int Xor(int a, int b);
static int And(int a, int b);
static int Shift_right(int a, int b);
static int Shift_left(int a, int b);

/* Global Variables */
int CALCULATION_ERROR = NO_ERROR;

static int Add(int a, int b) { return (a + b); }

static int Sub(int a, int b) { return (a - b); }

static int Mul(int a, int b) { return (a * b); }

static int Div(int a, int b) {
  if (b == 0) {
    CALCULATION_ERROR = DIV_BY_0;
    return (0);
  }
  return (a / b);
}

static int Mod(int a, int b) {
  if (b == 0) {
    CALCULATION_ERROR = MOD_BY_0;
    return (0);
  }
  return (a % b);
}

static int Xor(int a, int b) { return (a ^ b); }

static int And(int a, int b) { return (a & b); }

static int Shift_right(int a, int b) { return (a >> b); }

static int Shift_left(int a, int b) { return (a << b); }

static fcalc get_op_func(t_op_func *ops, char op) {
  int i;

  for (i = 0; ops[i].op != op && ops[i].op != 0; i++) {
  }
  if (ops[i].op == 0)
    CALCULATION_ERROR = INVALID_OP;
  return ops[i].calc;
}

static void get_numbers(char **argv, int *a, int *b) {
  char buffer_a[100];
  char buffer_b[100];
  get_numbers_from_str(argv[1], buffer_a);
  get_numbers_from_str(argv[1], buffer_b);
  if (buffer_a[0] == '\0' && buffer_b[0] == '\0')
    CALCULATION_ERROR = INVALID_NB;
  *a = ft_atoi(argv[1]);
  *b = ft_atoi(argv[3]);
}

static int check_errors() {
  switch (CALCULATION_ERROR) {
  case DIV_BY_0:
    ft_putstr("Stop : division by zero\n");
    return FALSE;
  case MOD_BY_0:
    ft_putstr("Stop : modulo by zero\n");
    return FALSE;
  case INVALID_NB:
    return FALSE;
  case INVALID_OP:
    ft_putstr("0\n");
    return FALSE;
  default:
    return TRUE;
  }
}

int main(int argc, char **argv) {
  t_op_func operators[] = {
      {'+', Add},         {'-', Sub},        {'*', Mul}, {'/', Div}, {'%', Mod},
      {'>', Shift_right}, {'<', Shift_left}, {'^', Xor}, {'&', And}, {0, 0},
  };
  int result;
  int a;
  int b;
  fcalc calc;

  if (argc != 4)
    return (1);
  calc = get_op_func(operators, argv[2][0]);
  if (check_errors() == FALSE)
    return (1);
  get_numbers(argv, &a, &b);
  if (check_errors() == FALSE)
    return (1);
  result = calc(a, b);
  if (check_errors() == FALSE)
    return (1);
  ft_putnbr(result);
  return (0);
}
