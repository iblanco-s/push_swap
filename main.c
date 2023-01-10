/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/10 19:24:30 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //A tener en cuenta: 
//MAX INT Y MIN INT, vienen de una string, larrain hace que cuando necesite lso espacios necesrarios para el numero y si son los mismo que los maxminint los compara uno a uno de izquierda a derecha y si hay alguno mayor error
//makefile esta regular
//pythontutor split 
#include "push_swap.h"

void	addlist(t_list *head, int i)
{
	t_list	*current;

	current = head;
	while (current -> next != NULL)
		current = current->next;
	current -> next = (t_list *) malloc(sizeof(t_list));
	current -> next -> data = i;
	current -> next -> next = NULL;
}

void	multarg(int argc, char **argv)
{
	t_list	*head;
	t_list	*temp;
	int		i;

	i = 2;
	errcheck(argv);
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		error();
	head -> data = ft_atoi(argv[i - 1]);
	head -> next = NULL;
	while (i < argc)
		addlist(head, ft_atoi(argv[i++]));
	mult_free(argv);
	doubles(head);
	while (head != NULL)
	{
		printf("%d\n", head->data);
		temp = head;
		head = head->next;
		free(temp);
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
