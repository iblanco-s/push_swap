/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:38:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/01 17:39:52 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funcion que libera el array de strings
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

//Funcion que libera la lista
void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

//Funcion que es llamada cuando atoi devuelve error
void	atoi_error(char **argv, t_list *head)
{
	free_list(head);
	free_err_check(argv);
}
