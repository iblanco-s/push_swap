/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:41:41 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/08 18:10:23 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **headA, int i)
{
	t_list	*temp;

	temp = *headA;
	if (*headA)
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = *headA;
		temp = *headA;
		*headA = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **headB, int i)
{
	t_list	*temp;

	temp = *headB;
	if (*headB)
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = *headB;
		temp = *headB;
		*headB = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **headA, t_list **headB)
{
	rotate_a(headA, 1);
	rotate_b(headB, 1);
	write(1, "rr\n", 3);
}
	//si uno/ambos no se han podido hacer printeo ss
	//y arriba siempre debo imprimir aunque no se pueda?

void	revrotate_a(t_list **headA, int i)
{
	t_list	*temp;

	temp = *headA;
	if (*headA)
	{
		while (temp -> next -> next)
			temp = temp -> next;
		temp -> next -> next = *headA;
		*headA = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rra\n", 4);
	}
}

void	revrotate_b(t_list **headB, int i)
{
	t_list	*temp;

	temp = *headB;
	if (*headB)
	{
		while (temp -> next -> next)
			temp = temp -> next;
		temp -> next -> next = *headB;
		*headB = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rrb\n", 4);
	}
}
