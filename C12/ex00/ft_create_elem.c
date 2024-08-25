#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

static t_list *init_list() {
  t_list *head;

  head = (t_list *)malloc(sizeof(t_list));
  if (!head)
    return (NULL);
  return head;
}

t_list *ft_create_elem(void *data) {
  t_list *head;

  head = init_list();
  head->next = NULL;
  head->data = data;

  return head;
}

int main(void) {
  t_list *head;

  char str[] = "Youssef";
  head = ft_create_elem((void *)str);

  printf("list->next = %s\nlist->data = %s\n", head->next ? "Elem 2" : "NULL",
         (char *)head->data);

  free(head);

  return EXIT_SUCCESS;
}
