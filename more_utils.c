/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:26:41 by iblanco-          #+#    #+#             */
/*   Updated: 2023/05/05 16:15:34 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_it_sorted(t_list *headA)
{
	int	sorted;

	sorted = 0;
	while (headA -> next && sorted == 0)
	{
		if (headA -> data > headA -> next -> data)
			sorted = 1;
		headA = headA -> next;
	}
	return (sorted);
}
