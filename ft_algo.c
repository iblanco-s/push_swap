/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:37 by inigo             #+#    #+#             */
/*   Updated: 2023/05/11 16:02:44 by iblanco-         ###   ########.fr       */
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
		if (temp->data > temp->next->data)
			swap_a(temp, 0);
		if (temp->next->data > temp->next->next->data)
			revrotate_a(headA, 0);
		temp = *headA;
		if (temp->data > temp->next->data)
			swap_a(temp, 0);
	}
}

void	ft_optimizator(t_list **headA, t_list *headb, int size)
{
	int	i;

	i = size;
	while (i > 3)
	{	
		if ((*headA)->data < (size - 3))
		{
			push_b(headA, &headb);
			i--;
		}
		else
			rotate_a(headA, 0);
	}
	ft_algo_3(headA);
	while (headb != NULL)
	{	
		push_a(headA, &headb);
		if ((*headA)->data > (*headA)->next->data)
			swap_a(*headA, 0);
	}
}

void	ft_algo_big(t_list **headA, int size)
{
	int		*nums;
	t_list	*headb;

	nums = ft_list_to_array(size, *headA);
	ft_order_sorted_position(nums, size, headA);
	free(nums);
	headb = NULL;
	if (size < 7)
		ft_optimizator(headA, headb, size);
	else
		ft_binary_radix(headA, headb, size);
}
