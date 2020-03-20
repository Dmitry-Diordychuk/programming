//  Dmitry Diordichuk
//  cort@mail.ru
//  Wed Mar 18 20:12:18 STD 2020

#ifndef __DR_LIST_H__
# define __DR_LIST_H__

# include <stdlib.h>

typedef struct 		s_linked
{
	struct s_linked	*next;
	int		number;
}			t_list;

t_list	*dr_create_node(int number);
t_list	*dr_list_last(t_list *list);
t_list	*dr_list_at(t_list *list, unsigned int nbr);
void	dr_list_clear(t_list **list);
void	dr_push_tail(t_list **list, int number);
void	dr_print_list(t_list *list);
void	dr_push_head(t_list **list, int number);
void	dr_push_array(t_list **list, int *ar, int len);
void	dr_list_change(t_list *list, int number, int at);
int	dr_list_size(t_list *list);

#endif
