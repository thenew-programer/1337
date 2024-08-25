#include "ft_list.h"
#include <stdlib.h>

static t_list *init_list() {
  t_list *head;

  head = (t_list *)malloc(sizeof(t_list));
  if (!head)
    return (NULL);
  head->next = NULL;
  head->data = NULL;
  return head;
}

void ft_list_push_back(t_list **begin_list, void *data) {
  t_list *elem;
  t_list *new;

  new = init_list();
  new->data = data;

  if (begin_list) {
    elem = *begin_list;
    while (elem->next)
      elem = elem->next;

    elem->next = new;
    return;
  }
  begin_list = &new;
}
