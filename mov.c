/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:20:19 by inigo             #+#    #+#             */
/*   Updated: 2023/03/04 13:38:44 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *headA, int i)
{
	int	temp;

	if (headA)
	{
		if (headA -> next)
		{
			temp = headA -> next -> data;
			headA -> next -> data = headA -> data;
			headA -> data = temp;
			if (i == 0)
				write(1, "sa\n", 3);
		}
	}
}

void	swap_b(t_list *headB, int i)
{
	int	temp;

	if (headB)
	{
		if (headB -> next)
		{
			temp = headB -> next -> data;
			headB -> next -> data = headB -> data;
			headB -> data = temp;
			if (i == 0)
				write(1, "sb\n", 3);
		}
	}
}

void	ss(t_list *headA, t_list *headB)
{
	swap_a(headA, 1);
	swap_b(headB, 1);
}

	//si uno/ambos no se han podido hacer printeo ss 
	//y arriba siempre debo imprimir aunque no se pueda?

void	push_a(t_list **headA, t_list **headB)
{
	t_list	*temp;

	if (*headA && *headB)
	{
		temp = *headB;
		*headB = temp -> next;
		temp -> next = *headA;
		*headA = temp;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **headA, t_list **headB)
{
	t_list	*temp;

	if (*headA && *headB)
	{
		temp = *headA;
		*headA = temp -> next;
		temp -> next = *headB;
		*headB = temp;
		write(1, "pb\n", 3);
	}
}
