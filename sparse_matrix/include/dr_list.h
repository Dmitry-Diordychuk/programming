/******************************************************************************/
/*                                                                            */
/*                         File: dr_list.h                                    */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 24th March 2020 10:27:26 pm                  */
/*                Last Modified: 26th March 2020 3:47:02 pm                   */
/*                                                                            */
/******************************************************************************/

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
t_list	*dr_list_intersection(t_list *a, t_list *b);
void	dr_list_insert(t_list **list, int at, int n);
void	dr_list_remove(t_list **list, int at);
void	dr_list_clear(t_list **list);
void	dr_push_tail(t_list **list, int number);
void	dr_print_list(t_list *list);
void	dr_push_head(t_list **list, int number);
void	dr_push_array(t_list **list, int *ar, int len);
void	dr_list_change(t_list *list, int number, int at);
int		dr_list_size(t_list *list);

#endif
