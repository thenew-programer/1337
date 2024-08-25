#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

static t_list *ft_list_last(t_list *begin_list) {
  t_list *tmp;

  tmp = begin_list;
  while (tmp->next)
    tmp = tmp->next;

  return tmp;
}

static int ft_list_size(t_list *begin_list) {
  t_list *tmp;
  int count;

  count = 0;
  tmp = begin_list;
  while (tmp) {
    count++;
    tmp = tmp->next;
  }
  return count;
}

static t_list *init_list() {
  t_list *head;

  head = (t_list *)malloc(sizeof(t_list));
  if (!head)
    return (NULL);
  head->next = NULL;
  head->data = NULL;
  return head;
}
void ft_list_push_front(t_list **begin_list, void *data) {
  t_list *element;

  element = init_list();
  element->next = *begin_list;
  element->data = data;
  *begin_list = element;
}

static t_list *ft_list_add_elem(t_list **head, void *data) {
  t_list *elem;
  t_list *new;

  new = init_list();
  new->data = data;

  if (head) {
    elem = *head;
    while (elem->next)
      elem = elem->next;

    elem->next = new;
  }

  return (new);
}

static t_list *ft_create_elem(void *data) {
  t_list *head;

  head = init_list();
  head->next = NULL;
  head->data = data;

  return head;
}
int main(void) {
  t_list *head, *tmp1, *tmp2, *last;
  char *data[] = {
      "Name", "Surname", "Email",     "Phone Number", "Social Security Number",
      "RIB",  "AGE",     "Birth Day", "Bullshit"};

  head = ft_create_elem(data[0]);
  for (int i = 1; i < 9; i++) {
    ft_list_add_elem(&head, data[i]);
  }
  ft_list_push_front(&head, (void *)"Added to the front");
  tmp1 = head;
  while (tmp1) {
    printf("list->next = %s\nlist->data = %s\n\n", tmp1->next ? "Elem" : "NULL",
           (char *)tmp1->data);
    tmp1 = tmp1->next;
  }

  printf("The size of this linked list => %d\n", ft_list_size(head));

  last = ft_list_last(head);
  printf("The last element of this list has data = %s\n", (char *)last->data);

  tmp1 = head;
  while (tmp1) {
    tmp2 = tmp1->next;
    free(tmp1);
    tmp1 = tmp2;
  }

  return EXIT_SUCCESS;
}
