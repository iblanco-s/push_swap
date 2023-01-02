/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/02 17:49:12 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //A tener en cuenta: 
//MAX INT Y MIN INT, vienen de una string, larrain hace que cuando necesite lso espacios necesrarios para el numero y si son los mismo que los maxminint los compara uno a uno de izquierda a derecha y si hay alguno mayor error
//hay dos formas que metan numeros, en un solo argumento o en varios argumentos (1 solo argumento usar split)
//debería funcionar esto = "++5"
//makefile esta mal

#include "push_swap.h"
#include <stdio.h>

void addlist(t_list *head, int i)
{
    t_list *current;
	
	current = head;
    while (current->next != NULL) 
        current = current->next;
    current->next = (t_list *) malloc(sizeof(t_list));
    current->next->data = i;
    current->next->next = NULL;
}

void multarg(int argc, char **argv)
{
	t_list	*head;
	int		i;

	i = 2;
	head = (t_list *)malloc(sizeof(t_list));
	// if (!head)
	// 	return ();
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

int	main (int argc, char **argv)
{
	if (argc < 2)
		return(0);
	else if (argc == 2)
		return(0); //1arg();
	else
		multarg(argc, argv);
}

