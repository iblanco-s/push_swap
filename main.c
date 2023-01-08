/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/08 12:44:24 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //A tener en cuenta: 
//MAX INT Y MIN INT, vienen de una string, larrain hace que cuando necesite lso espacios necesrarios para el numero y si son los mismo que los maxminint los compara uno a uno de izquierda a derecha y si hay alguno mayor error
//makefile esta mal

#include "push_swap.h"
#include <stdio.h>

void	error(void)
{
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

void	addlist(t_list *head, int i)
{
	t_list	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_list *) malloc(sizeof(t_list));
	current->next->data = i;
	current->next->next = NULL;
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

void	multarg(int argc, char **argv)
{
	t_list	*head;
	int		i;

	i = 2;
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		error();
	head -> data = atoi(argv[i - 1]);
	head -> next = NULL;
	while (i < argc)
		addlist(head, atoi(argv[i++]));
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int	count_str(char **str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	if (i < 2)
		error();
	return (i);
}

int	main(int argc, char **argv)
{
	char	**str;

	if (argc < 2)
		error();
	else if (argc == 2)
	{
		str = ft_mod_split(argv[1], ' ');
		argc = count_str(str);
		multarg(argc, str);
	}
	else
		multarg(argc, argv);
}
