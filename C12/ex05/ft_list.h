#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct s_list {
  struct s_list *next;
  void *data;
} t_list;

t_list *ft_list_push_strs(int size, char **strs);
t_list *ft_create_elem(void *);

#endif /* FT_LIST_H */
