#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct s_list {
  struct s_list *next;
  void *data;
} t_list;

int ft_list_size(t_list *);

#endif /* FT_LIST_H */
