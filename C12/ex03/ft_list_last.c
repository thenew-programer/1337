#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list) {
  t_list *tmp;

  tmp = begin_list;
  while (tmp->next)
    tmp = tmp->next;

  return tmp;
}
