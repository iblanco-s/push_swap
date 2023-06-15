/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:04:40 by inigo             #+#    #+#             */
/*   Updated: 2023/05/15 16:03:53 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *nums, int low, int high)
{
	int	temp;
	int	reference;
	int	i;
	int	j;

	reference = nums[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (nums[j] <= reference)
		{
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
		}
		j++;
	}
	temp = nums[i];
	nums[i] = nums[high];
	nums[high] = temp;
	return (i);
}

void	quicksort(int *nums, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(nums, low, high);
		quicksort(nums, low, pivot - 1);
		quicksort(nums, pivot + 1, high);
	}
}

void	ft_order_sorted_position(int *nums, int size, t_list **headA)
{
	int		i;
	t_list	*temp;

	i = -1;
	quicksort(nums, 0, size - 1);
	temp = *headA;
	while (temp)
	{
		temp->index = temp->data;
		temp = temp->next;
	}
	temp = *headA;
	while (temp)
	{
		while (i++ < size)
		{
			if (temp->index == nums[i])
			{
				temp->data = i;
				i = -1;
				break ;
			}
		}
		temp = temp->next;
	}
}

void	ft_binary_radix(t_list **headA, t_list *headB, int size)
{
	int	i;
	int	j;
	int	count_pb;

	i = -1;
	j = 0;
	count_pb = 0;
	while (ft_is_it_sorted(*headA) == 1 && i++ < 32)
	{
		while (j < size)
		{
			if (((*headA)->data >> i) & 1)
				rotate_a(headA, 0);
			else
			{
				push_b(headA, &headB);
				count_pb++;
			}	
			j++;
		}
		while (count_pb--)
			push_a(headA, &headB);
		count_pb = 0;
		j = 0;
	}
}
