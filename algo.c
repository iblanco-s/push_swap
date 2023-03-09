/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:37 by inigo             #+#    #+#             */
/*   Updated: 2023/03/09 17:21:46 by iblanco-         ###   ########.fr       */
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
			revrotate_a(&temp, 0);
		if (temp -> data > temp -> next -> next -> data)
			swap_a(temp, 0);
	}
}