/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:04:40 by inigo             #+#    #+#             */
/*   Updated: 2023/04/15 19:41:29 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// https://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%0Avoid%20quicksort%28int%20*%20nums,%20int%20low,%20int%20high%29%3B%0Avoid%20print_array%28int%20*%20nums,%20int%20size%29%3B%0A%0Aint%20%20%20%20partition%28int%20*%20nums,%20int%20low,%20int%20high%29%0A%7B%0A%20%20%20%20int%20temp%3B%0A%20%20%20%20int%20reference%3B%0A%20%20%20%20%0A%20%20%20%20reference%20%3D%20nums%5Bhigh%5D%3B%0A%20%20%20%20int%20i%20%3D%20low%20-%201%3B%0A%20%20%20%20int%20j%20%3D%20low%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28j%20%3C%20high%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28nums%5Bj%5D%20%3C%3D%20reference%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20nums%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20nums%5Bi%5D%20%3D%20nums%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20nums%5Bj%5D%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20j%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20temp%20%3D%20nums%5Bi%20%2B%201%5D%3B%0A%20%20%20%20nums%5Bi%20%2B%201%5D%20%3D%20nums%5Bhigh%5D%3B%0A%20%20%20%20nums%5Bhigh%5D%20%3D%20temp%3B%0A%0A%20%20%20%20return%20i%20%2B%201%3B%0A%20%20%20%20%0A%7D%0A%0Avoid%20quicksort%28int%20*%20nums,%20int%20low,%20int%20high%29%0A%7B%0A%20%20%20%20if%20%28low%20%3C%20high%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20int%20pivot%20%3D%20partition%28nums,%20low,%20high%29%3B%0A%20%20%20%20%20%20%20%20quicksort%28nums,%20low,%20pivot%20-%201%29%3B%0A%20%20%20%20%20%20%20%20quicksort%28nums,%20pivot%20%2B%201,%20high%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0A/*%0Aint%20partition%28int%20*%20nums,%20int%20low,%20int%20high%29%0A%7B%0A%20%20%20%20int%20temp%3B%0A%20%20%20%20int%20pivot%20%3D%20nums%5Bhigh%5D%3B%0A%20%20%20%20int%20i%20%3D%20low%20-%201%3B%0A%20%20%20%20%0A%20%20%20%20for%20%28int%20j%20%3D%20low%3B%20j%20%3C%20high%3B%20j%2B%2B%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28nums%5Bj%5D%20%3C%3D%20pivot%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20nums%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20nums%5Bi%5D%20%3D%20nums%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20nums%5Bj%5D%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20temp%20%3D%20nums%5Bi%20%2B%201%5D%3B%0A%20%20%20%20nums%5Bi%20%2B%201%5D%20%3D%20nums%5Bhigh%5D%3B%0A%20%20%20%20nums%5Bhigh%5D%20%3D%20temp%3B%0A%20%20%20%20%0A%20%20%20%20return%20i%20%2B%201%3B%0A%7D%0A*/%0Aint%20main%28%29%0A%7B%0A%20%20%20%20int%20nums%5B%5D%20%3D%20%7B7,%203,%209,%204,%205,%200,%201,%206,%202,%208%7D%3B%0A%20%20%20%20int%20size%20%3D%20sizeof%28nums%29%20/%20sizeof%28nums%5B0%5D%29%3B%0A%0A%20%20%20%20printf%28%22Antes%20de%20QuickSort%3A%5Cn%22%29%3B%0A%20%20%20%20print_array%28nums,%20size%29%3B%0A%0A%20%20%20%20quicksort%28nums,%200,%20size%20-%201%29%3B%0A%0A%20%20%20%20printf%28%22%5CnDespu%C3%A9s%20de%20QuickSort%3A%5Cn%22%29%3B%0A%20%20%20%20print_array%28nums,%20size%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20print_array%28int%20*%20nums,%20int%20size%29%0A%7B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20size%3B%20i%2B%2B%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%22,%20nums%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

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
