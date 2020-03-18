#include <stdlib.h>
#include <stdio.h>

typedef struct		s_linked
{
	struct s_linked	*next;
	int				number;
}					t_list;

t_list	*create_node(int number);
void	add_tail(t_list *list, int number);
void	print_list(t_list *list);

void	add_tail(t_list *list, int number)
{
	t_list	*new_tail;
	t_list	*temp;
	
	temp = list;
	new_tail = create_node(number);
	if (new_tail)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_tail;
	}
}

//malloc
t_list	*create_node(int number)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->next = NULL;
		new_node->number = number;
	}
	return (new_node);
}

void	print_list(t_list *list)
{
	t_list *temp;

	temp = list;
	while (temp->next != NULL)
	{
		printf("%d, ", temp->number);
		temp = temp->next;
	}
	printf("%d.\n", temp->number);
}

void	add_head(t_list **list, int number)
{
	t_list *new_head;

	new_head = create_node(number);
	if (new_head && list)
	{
		new_head->next = *list;
		*list = new_head;
	}
}

int	main(void)
{
	t_list *list;
	
	list = create_node(1);
	add_tail(list, 2);
	add_tail(list, 3);
	add_head(&list, 4);

	print_list(list);
	return (0);
}
