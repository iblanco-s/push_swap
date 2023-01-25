/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:17:26 by inigo             #+#    #+#             */
/*   Updated: 2023/01/25 19:58:28 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	//cuando sale si el numero mayor que long da leaks porque llamo error sin liberar
	//hacer comando para git add-commit-push
	write(1, "Error", 5);
	exit(0);
}

void	doubles(t_list *head)
{
	t_list	*temp;

	while (head -> next != NULL)
	{
		temp = head -> next;
		while (temp != NULL)
		{
			if (head->data == temp-> data)
				error();
			temp = temp->next;
		}
		head = head->next;
	}
}

void	errcheck(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (!argv[i][j])
			error();
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j + 1] > 58 || argv[i][j + 1] < 47)
				error();
			j++;
		}
		while (argv[i][j])
		{
			if (argv[i][j] > 58 || argv[i][j] < 47)
				error();
			j++;
		}
		i++;
	}
}

void	mult_free(char **argv)
{
	int	i;

	i = 1;
	if (argv[0] == NULL)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
