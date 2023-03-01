/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/01 17:30:18 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //A tener en cuenta: 
//makefile esta regular
//pythontutor split ¿whats the point?
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
	t_list	*aux;
	int		i;

	i = 2;
	err_check(argv);
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		free_err_check(argv);
	head -> data = ft_atoi(argv[i - 1], argv, head);
	head -> next = NULL;
	while (i < argc)
		addlist(head, ft_atoi(argv[i++], argv, head));
	mult_free(argv);
	doubles(head);
	aux = head;
	while (head != NULL)
	{
		printf("%d\n", head->data);
		temp = head;
		head = head->next;
	}
	free_list(aux);
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
