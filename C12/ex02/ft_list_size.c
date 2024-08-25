#include "ft_list.h"

int ft_list_size(t_list *begin_list) {
  t_list *tmp;
  int count;

  count = 0;
  while (tmp) {
    count++;
    tmp = tmp->next;
  }
  return count;
}
