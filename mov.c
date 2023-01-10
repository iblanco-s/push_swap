/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:20:19 by inigo             #+#    #+#             */
/*   Updated: 2023/01/10 19:46:26 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_list *headA)
{
	int	temp;
	if (headA)
	{
		if (headA -> next)
		{
			temp = headA -> next -> data;
			headA -> next -> data = headA -> data;
			headA -> data = temp;
			write(1, "sa", 2);
		}
	}
}

int	swap_b(t_list *headB)
{
	int	temp;
	if (headB)
	{
		if (headB -> next)
		{
			temp = headB -> next -> data;
			headB -> next -> data = headB -> data;
			headB -> data = temp;
			write(1, "sb", 2);
		}
	}
}

void	ss(t_list *headA, t_list *headB)
{
	swap_a(headA);
	swap_b(headB);
	//si uno/ambos no se han podido hacer printeo ss y arriba siempre debo imprimir aunque no se pueda?
}

void	push_a(t_list *headA, t_list *headB)
{
	if (headA && headB)
	{
		headB -> next = headA;
		headA = headB;
		write(1, "pa", 2);
	}
}

void	push_b(t_list *headA, t_list *headB)
{
	if (headA && headB)
	{
		headA -> next = headB;
		headB = headA;
		write(1, "pa", 2);
	}
}

int	rotate_b(t_list *headB)
{
	t_list	*temp;
	
	temp = headB;
	if (headB)
	{
		while (temp)
			temp =  temp -> next;
		temp -> next = headB;
		headB -> next = NULL;
		write(1, "rb", 2);
	}
}