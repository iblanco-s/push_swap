/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:02 by iblanco-          #+#    #+#             */
/*   Updated: 2023/04/29 14:09:12 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, char **argv, t_list *head)
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
		atoi_error(argv, head);
	return ((int)ret);
}

int	ft_strlen(const char *a)
{
	int	len;

	len = 0;
	while (a[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	c;
	size_t	k;

	c = 0;
	k = 0;
	while (src[c] != '\0')
		c++;
	if (len > 0)
	{
		while (src[k] != '\0')
		{
			dest[k] = src[k];
			k++;
			if (k == len)
			{
				k--;
				break ;
			}
		}
		dest[k] = '\0';
	}
	return (c);
}

//tamaño lista enlazada
int	ft_count_list(t_list *head)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	*ft_list_to_array(int size, t_list *head)
{
	int		*nums;
	int		i;
	t_list	*temp;

	i = 0;
	temp = head;
	nums = malloc(sizeof(int) * size);
	while (i < size)
	{
		nums[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (nums);
}
