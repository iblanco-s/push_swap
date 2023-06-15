/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:26:41 by iblanco-          #+#    #+#             */
/*   Updated: 2023/05/19 17:49:22 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_it_sorted(t_list *headA)
{
	int	sorted;

	sorted = 0;
	while (headA->next && sorted == 0)
	{	
		if (headA->data > headA->next->data)
			sorted = 1;
		headA = headA->next;
	}
	return (sorted);
}

void	ft_bug_atoi(const char *str, char **argv)
{
	int			i;
	int			j;
	long int	ret;

	i = 0;
	j = 1;
	ret = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	ret *= j;
	if (ret < -2147483648 || ret > 2147483647)
		free_err_check(argv);
}
