/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:17:26 by inigo             #+#    #+#             */
/*   Updated: 2023/05/15 17:02:19 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

//Funcion que comprueba que no hay numeros repetidos
void	doubles(t_list *head)
{
	t_list	*temp;
	t_list	*aux;

	aux = head;
	while (head -> next != NULL)
	{
		temp = head -> next;
		while (temp != NULL)
		{
			if (head->data == temp-> data)
			{
				free_list(aux);
				error();
			}
			temp = temp->next;
		}
		head = head->next;
	}
}

//Funcion que libera el array de strings y llama a error
void	free_err_check(char **argv)
{
	mult_free(argv);
	error();
}

//Funcion que comprueba que los argumentos son numeros
void	err_check(char **argv)
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
			free_err_check(argv);
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j + 1] > 58 || argv[i][j + 1] < 47)
				free_err_check(argv);
			j++;
		}
		while (argv[i][j])
		{
			if (argv[i][j] > 58 || argv[i][j] < 47)
				free_err_check(argv);
			j++;
		}
		i++;
	}
}
