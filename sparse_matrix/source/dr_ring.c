// Dmitry Diordichuk
// cort@mail.ru
// Thu Mar 19 21:46:23 MSK 2020

#include "dr_list.h"
#include "dr_ring.h"

void	dr_loop_list(t_list **head)
{
	t_list *tail;

	if (*head)
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = *head;
	}
}

void	dr_unloop_list(t_list **head)
{
	t_list *tail;

	tail = *head;
	if (*head)
	{
		while (tail->next != *head)
			tail = tail->next;
		tail->next = NULL;
	}
}
