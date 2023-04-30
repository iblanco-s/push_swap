/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:37 by inigo             #+#    #+#             */
/*   Updated: 2023/04/30 19:38:38 by iblanco-         ###   ########.fr       */
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
void	ft_algo_5(t_list **headA, int size)
{
	int		*nums;
	t_list	*headb;

	nums = ft_list_to_array(size, *headA);
	ft_order_sorted_position(nums, size, headA);
	free(nums);
	headb = (t_list *)malloc(sizeof(t_list));
	while (size > 3)
	{
		if ((*headA)->data == 0 || (*headA)->data == 1)
		{
			push_b(headA, &headb);
			size--;
		}
		else
			rotate_a(headA, 0);
	}
	ft_algo_3(headA);
	push_a(headA, &headb);
	push_a(headA, &headb);
	if ((*headA)->data == 1)
		swap_a(*headA, 0);
	free(headb);
}

//algoritmo para ordenar mas de 5 elementos con dos stacks
void	ft_algo_big(t_list **headA, int size)
{
	int		*nums;
	t_list	*headb;

	nums = ft_list_to_array(size, *headA);
	ft_order_sorted_position(nums, size, headA);
	free(nums);
	headb = (t_list *)malloc(sizeof(t_list));
	ft_binary_radix(*headA, headb, size);
	free(headb);
}
