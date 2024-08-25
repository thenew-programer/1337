#ifndef DO_OP_H
#define DO_OP_H

/* Calculation Errors */
#define FALSE 000
#define TRUE 001
#define NO_ERROR 100
#define DIV_BY_0 101
#define MOD_BY_0 102
#define INVALID_OP 103
#define INVALID_NB 104

typedef struct s_op_func {
  char op;
  int (*calc)(int, int);
} t_op_func;

typedef int (*fcalc)(int, int);

int ft_atoi(char *);
void ft_putnbr(int);
void ft_putstr(char *);
char *get_numbers_from_str(char *, char *);
#endif
