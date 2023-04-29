/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:37 by inigo             #+#    #+#             */
/*   Updated: 2023/04/29 14:13:28 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//algoritmo para ordenar 3 elementos con dos stacks
void	ft_algo_3(t_list **headA)
{
	t_list	*temp;

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
	t_list	*temp;
	t_list	*headb;
	int		i;

	i = 0;
	headb = NULL;
	temp = *headA;
	while (i < 2)
	{
		if (temp -> data < temp -> next -> data)
		{
			push_b(headA, &headb);
			i++;
		}
		else
			rotate_a(headA, 0);
		temp = *headA;
	}
	ft_algo_3(headA);
	while (i > 0)
	{
		push_a(headA, &headb);
		i--;
	}
}

//algoritmo para ordenar mas de 5 elementos con dos stacks
void	ft_algo_big(t_list **headA, int size)
{
	int		*nums;
	t_list	*headb;

	nums = ft_list_to_array(size, *headA);
	ft_order_sorted_position(nums, size, headA);
	headb = (t_list *)malloc(sizeof(t_list));
	ft_binary_radix(*headA, headb, size);
}
