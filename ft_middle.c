/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:04:40 by inigo             #+#    #+#             */
/*   Updated: 2023/04/15 19:22:48 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rewrite this function using 42 norm

int	partition(int *nums, int low, int high)
{
	int	temp;
	int	reference;
	int	i;
	int	j;

	reference = nums[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (nums[j] <= reference)
		{
			i++;
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		j++;
	}
	temp = nums[i + 1];
	nums[i + 1] = nums[high];
	nums[high] = temp;
	return (i + 1);
}

/* 
int    partition(int * nums, int low, int high)
{
    int temp;
    int reference;
	int i;
	int j;
    
    reference = nums[high];
	i = low - 1;
	j = low;
    
    while (j < high)
    {
        if (nums[j] <= reference)
        {
            i++;
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        j++;
    }
    temp = nums[i + 1];
    nums[i + 1] = nums[high];
    nums[high] = temp;
    return i + 1; 
}
*/
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

int	ft_middle(int *nums, int size)
{
	int	middle;

	quicksort(nums, 0, size - 1);
	middle = nums[size / 2];
	return (middle);
}
