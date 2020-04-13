/******************************************************************************/
/*                                                                            */
/*                         File: dr_list.c                                    */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 24th March 2020 10:27:26 pm                  */
/*                Last Modified: 25th March 2020 2:34:49 pm                   */
/*                                                                            */
/******************************************************************************/

#include "dr_list.h"
#include "dr_print.h"

t_list	*dr_list_rmdup(t_list **list)
{
	int i;
	int j;

	i = 1;
	while (i < dr_list_size(*list) + 1)
	{
		j = i + 1;
		while (j < dr_list_size(*list) + 1)
		{
			if (dr_list_at(*list, i)->number == dr_list_at(*list, j)->number)
				dr_list_remove(list, j);
			j++;
		}
		i++;
	}
	return (*list);
}

void	dr_list_addlist(t_list **list_a, t_list *list_b)
{
	if (list_b == NULL)
		return	;
	while (list_b->next != NULL)
	{
		dr_push_tail(list_a, list_b->number);
		list_b = list_b->next;
	}
	dr_push_tail(list_a, list_b->number);
}

int	dr_list_find(t_list *list, int elem)
{
	int i;
	t_list *node;

	i = 1;
	while ((node = dr_list_at(list, i)) != NULL)
	{
		if (node->number == elem)
			return (i);
		i++;
	}
	return (-1);
}

void dr_list_insert(t_list **list, int at, int n)
{
	int		i;
	t_list	*cur;
	t_list	*prev;
	t_list	*new_elem;

	if (*list && at > 0 && at < dr_list_size(*list) + 1)
	{
		new_elem = dr_create_node(n);
		prev = NULL;
		cur = *list;
		i = 0;
		while (i < at)
		{
			prev = cur;
			cur = cur->next;
			i++;
		}
		if (prev)
			prev->next = new_elem;
		else
			*list = new_elem;
		new_elem->next = cur;
	}
}

int	dr_list_find_predicate(t_list *list, int a, int (*predicate)(int a, int b))
{
	int		i;
	int		save;
	t_list	*x;

	i = 1;
	save = -1;
	while ((x = dr_list_at(list, i)) != NULL)
	{
		if (predicate(a, x->number) > 0)
		{
			if (dr_list_at(list, i + 1) != NULL)
			{
				save = i;
				i++;
				continue;
			}
			if (save == -1)
				return (i);
			else
				return (++save);
		}
		i++;
	}
	if (save != -1)
		return (save);
	return (-1);
}

void	dr_list_remove(t_list **list, int at)
{
	int		i;
	t_list	*cur;
	t_list	*prev;

	if (*list && at > 0 && at < dr_list_size(*list) + 1)
	{
		prev = NULL;
		cur = *list;
		i = 0;
		while (i < at - 1)
		{
			prev = cur;
			cur = cur->next;
			i++;
		}
		if (prev)
			prev->next = cur->next;
		else
			*list = (*list)->next;
		free(cur);
	}
}

t_list	*dr_list_intersection(t_list *a, t_list *b)
{
	t_list *temp_b;
	t_list *intersect;

	intersect = NULL;
	temp_b = b;
	while (a != NULL)
	{
		b = temp_b;
		while (b != NULL)
		{
			if (a->number == b->number)
				dr_push_tail(&intersect, a->number);
			b = b->next;
		}
		a = a->next;
	}
	return (intersect);
}

void	dr_push_tail(t_list **list, int number)
{
	t_list	*temp;
	t_list	*new_tail;

	temp = *list;
	new_tail = dr_create_node(number);
	if (*list == NULL)
		*list = new_tail;
	else if (new_tail)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_tail;
	}
}

t_list	*dr_create_node(int number)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->next = NULL;
		new_node->number = number;
	}
	else
	{
		dr_putstr("MALLOC ERROR!");
	}
	return (new_node);
}

void	dr_print_list(t_list *list)
{
	t_list *temp;

	if (list)
	{
		temp = list;
		while (temp->next != NULL)
		{
			dr_putnbr(temp->number);
			dr_putstr(",\t");
			temp = temp->next;
		}
		dr_putnbr(temp->number);
		dr_putstr(".\n");
	}
}

void	dr_push_head(t_list **list, int number)
{
	t_list *new_head;

	new_head = dr_create_node(number);
	if (new_head && list)
	{
		new_head->next = *list;
		*list = new_head;
	}
}

int	dr_list_size(t_list *list)
{
	int size;

	if (list)
	{
		size = 0;
		while (list->next != NULL)
		{
			list = list->next;
			size++;
		}
		return (++size);
	}
	return (-1);
}

t_list	*dr_list_last(t_list *list)
{
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
	}
	return (list);
}

void	dr_list_clear(t_list **list)
{
	if (*list)
	{
		while ((*list)->next != NULL)
		{
			while ((*list)->next->next != NULL)
				(*list) = (*list)->next;
			free((*list)->next);
			(*list)->next = NULL;
		}
		free(*list);
		*list = NULL;
	}
}

t_list	*dr_list_at(t_list *list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (list == NULL)
		return (list = NULL);
	while (list->next != NULL)
	{
		if (i == nbr - 1)
			return (list);
		list = list->next;
		i++;
	}
	if (i == nbr - 1)
		return (list);
	return (list = NULL);
}

void	dr_push_array(t_list **list, int *ar, int len)
{
	int i;

	if (*list)
	{
		i = 0;
		while (i < len)
		{
			dr_push_tail(&(*list), ar[i]);
			i++;
		}
	}
	else if (len > 0)
	{
		*list = dr_create_node(ar[0]);
		i = 1;
		while (i < len)
		{
			dr_push_tail(&(*list), ar[i]);
			i++;
		}
	}
}

void	dr_list_change(t_list *list, int number, int at)
{
	int i;

	i = 1;
	while (i != at)
	{
		if (list->next == NULL)
			return ;
		list = list->next;
		i++;
	}
	list->number = number;
}
