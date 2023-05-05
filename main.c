/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/05/05 16:57:56 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addlist(t_list *head, int i)
{
	t_list	*current;

	current = head;
	while (current -> next != NULL)
		current = current->next;
	current->next = (t_list *) malloc(sizeof(t_list));
	current->next->data = i;
	current->next->next = NULL;
}

void	ft_choose(t_list **headA)
{
	int	i;

	i = ft_count_list(*headA);
	if (i == 3)
		ft_algo_3(headA);
	else if (i == 2)
	{
		if ((*headA)->data > (*headA)->next->data)
			swap_a(*headA, 0);
	}
	else
		ft_algo_big(headA, i);
}

void	multarg(int argc, char **argv)
{
	t_list	*head;
	int		i;

	i = 2;
	err_check(argv);
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		free_err_check(argv);
	head->data = ft_atoi(argv[i - 1], argv, head);
	head->next = NULL;
	while (i < argc)
		addlist(head, ft_atoi(argv[i++], argv, head));
	mult_free(argv);
	doubles(head);
	ft_choose(&head);
	free_list(head);
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
		return (0);
	else if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (0);
		str = ft_mod_split(argv[1], ' ');
		argc = count_str(str);
		multarg(argc, str);
	}
	else
		multarg(argc, argv);
}
