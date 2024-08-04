#ifndef BOOL
#define BOOL

#define TRUE 1
#define FALSE 0
#define SUCCESS FALSE
#define EVEN(x) (!(x % 2))
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

#include <unistd.h>

typedef int t_bool;

#endif /* BOOL */
