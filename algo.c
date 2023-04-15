/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:37 by inigo             #+#    #+#             */
/*   Updated: 2023/03/28 19:43:05 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//algoritmo para ordenar 3 elementos con dos stacks
void	ft_algo_3(t_list **headA)
{
	t_list *temp;
	
	temp = *headA;
	if (temp -> next != NULL)
	{
		if (temp -> data > temp -> next -> data)
			swap_a(temp, 0);
		if (temp -> next -> data > temp -> next -> next-> data)
			revrotate_a(headA, 0);
		temp = *headA;
		if (temp -> data > temp -> next -> data)
			swap_a(temp, 0);
	}
}

//algoritmo para ordenar 5 elementos con dos stacks
//POSIBLEMENTE INNECESARIO PARA MI APROACH
void	ft_algo_5(t_list **headA)
{
	t_list *temp;
	t_list	*headB;
	int i;
	
	i = 0;
	headB = NULL;
	temp = *headA;
	while (i < 2)
	{
		if (temp -> data < temp -> next -> data)
		{
			//esta mal, deberia enviarse solo los 2 mas pequeños
			push_b(headA, &headB);
			i++;
		}
		else
			rotate_a(headA, 0);
		temp = *headA;
	}
	ft_algo_3(headA);
	while (i > 0)
	{
		push_a(headA, &headB);
		i--;
	}
}

//algoritmo para ordenar mas de 5 elementos con dos stacks
void	ft_algo_big(t_list **headA, int size)
{
	int middle;
	
	middle = ft_middleNum(ft_listToArray(size, *headA), size);
}