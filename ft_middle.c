/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:04:40 by inigo             #+#    #+#             */
/*   Updated: 2023/04/21 16:59:44 by iblanco-         ###   ########.fr       */
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

int	ft_middleNum(int *nums, int size)
{
	int i;
	int	middle;

	i = 0;
	quicksort(nums, 0, size - 1);
	middle = nums[(size / 2)];
	free (nums);
	return (middle);
}
