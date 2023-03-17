/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:40 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/17 17:00:03 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //A tener en cuenta: 
//makefile esta regular
#include "push_swap.h"
//https://pythontutor.com/visualize.html#code=%23include%20%3Cunistd.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Atypedef%20struct%20s_list%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20data%3B%0A%20%20%20%20struct%20s_list%20%20%20%20*next%3B%0A%7D%20%20%20%20t_list%3B%0A%0Avoid%20%20%20%20swap_a%28t_list%20*headA,%20int%20i%29%0A%7B%0A%20%20%20%20int%20%20%20%20temp%3B%0A%0A%20%20%20%20if%20%28headA%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28headA%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20headA%20-%3E%20next%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headA%20-%3E%20next%20-%3E%20data%20%3D%20headA%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headA%20-%3E%20data%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28i%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22sa%5Cn%22,%203%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20%20%20%20revrotate_a%28t_list%20**headA,%20int%20i%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20*temp%3B%0A%0A%20%20%20%20temp%20%3D%20*headA%3B%0A%20%20%20%20if%20%28*headA%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20while%20%28temp%20-%3E%20next%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20temp%20-%3E%20next%3B%0A%20%20%20%20%20%20%20%20temp%20-%3E%20next%20-%3E%20next%20%3D%20*headA%3B%0A%20%20%20%20%20%20%20%20*headA%20%3D%20temp%20-%3E%20next%3B%0A%20%20%20%20%20%20%20%20temp%20-%3E%20next%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20if%20%28i%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22rra%5Cn%22,%204%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20%20%20%20ft_count_list%28t_list%20*head%29%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20i%3B%0A%20%20%20%20t_list%20%20%20%20*temp%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20temp%20%3D%20head%3B%0A%20%20%20%20while%20%28temp%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20temp%20%3D%20temp-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0Avoid%20ft_algo_3%28t_list%20*headA%29%0A%7B%0A%20%20%20%20if%20%28headA-%3Enext%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28headA-%3Edata%20%3E%20headA-%3Enext-%3Edata%29%0A%20%20%20%20%20%20%20%20%20%20%20%20swap_a%28headA,%200%29%3B%0A%20%20%20%20%20%20%20%20if%20%28headA-%3Enext-%3Edata%20%3E%20headA-%3Enext-%3Enext-%3Edata%29%0A%20%20%20%20%20%20%20%20%20%20%20%20revrotate_a%28%26headA,%200%29%3B%0A%20%20%20%20%20%20%20%20if%20%28headA-%3Edata%20%3E%20headA-%3Enext-%3Enext-%3Edata%29%0A%20%20%20%20%20%20%20%20%20%20%20%20swap_a%28headA,%200%29%3B%0A%20%20%20%20%7D%0A%7D%0Avoid%20%20%20%20choose%28t_list%20**headA%29%0A%7B%0A%20%20%20%20if%20%28ft_count_list%28*headA%29%20%3D%3D%203%29%0A%20%20%20%20%20%20%20%20ft_algo_3%28*headA%29%3B%0A%7D%0A%0Avoid%20%20%20%20multarg%28t_list%20*head%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20*aux%3B%0A%0A%20%20%20%20choose%28%26head%29%3B%0A%20%20%20%20//revrotate_a%28%26head,%200%29%3B%0A%20%20%20%20aux%20%3D%20head%3B%0A%20%20%20%20while%20%28head%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%5Cn%22,%20head-%3Edata%29%3B%0A%20%20%20%20%20%20%20%20head%20%3D%20head-%3Enext%3B%0A%20%20%20%20%7D%0A%7D%0Aint%20main%28%29%0A%7B%0A%20%20%20%20//%20Creamos%20el%20primer%20nodo%20y%20lo%20inicializamos%20con%20el%20valor%202%0A%20%20%20%20t_list%20*head%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20if%20%28!head%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20return%201%3B%0A%20%20%20%20%7D%0A%20%20%20%20head-%3Edata%20%3D%202%3B%0A%20%20%20%20head-%3Enext%20%3D%20NULL%3B%0A%0A%20%20%20%20//%20Creamos%20el%20segundo%20nodo%20y%20lo%20inicializamos%20con%20el%20valor%203%0A%20%20%20%20t_list%20*second%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20if%20%28!second%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20return%201%3B%0A%20%20%20%20%7D%0A%20%20%20%20second-%3Edata%20%3D%203%3B%0A%20%20%20%20second-%3Enext%20%3D%20NULL%3B%0A%0A%20%20%20%20//%20Enlazamos%20el%20segundo%20nodo%20al%20primer%20nodo%0A%20%20%20%20head-%3Enext%20%3D%20second%3B%0A%0A%20%20%20%20//%20Creamos%20el%20tercer%20nodo%20y%20lo%20inicializamos%20con%20el%20valor%201%0A%20%20%20%20t_list%20*third%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20if%20%28!third%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20return%201%3B%0A%20%20%20%20%7D%0A%20%20%20%20third-%3Edata%20%3D%201%3B%0A%20%20%20%20third-%3Enext%20%3D%20NULL%3B%0A%0A%20%20%20%20//%20Enlazamos%20el%20tercer%20nodo%20al%20segundo%20nodo%0A%20%20%20%20second-%3Enext%20%3D%20third%3B%0A%20%20multarg%28head%29%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
//https://pythontutor.com/visualize.html#code=%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Atypedef%20struct%20s_list%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20%20%20%20%20%20data%3B%0A%20%20%20%20struct%20s_list%20%20%20*next%3B%0A%7D%20%20%20t_list%3B%0A%0Avoid%20%20%20%20revrotate_a%28t_list%20**headA,%20int%20i%29%0A%7B%0A%20%20%20%20t_list%20%20*temp%3B%0A%0A%20%20%20%20temp%20%3D%20*headA%3B%0A%20%20%20%20if%20%28*headA%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20while%20%28temp%20-%3E%20next%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20temp%20-%3E%20next%3B%0A%20%20%20%20%20%20%20%20temp%20-%3E%20next%20-%3E%20next%20%3D%20*headA%3B%0A%20%20%20%20%20%20%20%20*headA%20%3D%20temp%20-%3E%20next%3B%0A%20%20%20%20%20%20%20%20temp%20-%3E%20next%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20if%20%28i%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22rra%5Cn%22,%204%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20%20%20//%20Creamos%20la%20lista%20enlazada%20con%203%20nodos%0A%20%20%20%20t_list%20*head%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20head-%3Edata%20%3D%202%3B%0A%0A%20%20%20%20t_list%20*second%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20second-%3Edata%20%3D%203%3B%0A%20%20%20%20head-%3Enext%20%3D%20second%3B%0A%0A%20%20%20%20t_list%20*third%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20third-%3Edata%20%3D%201%3B%0A%20%20%20%20second-%3Enext%20%3D%20third%3B%0A%20%20%20%20third-%3Enext%20%3D%20NULL%3B%0A%0A%20%20%20%20//%20Llamamos%20a%20la%20funci%C3%B3n%20revrotate_a%20con%20la%20cabeza%20de%20la%20lista%20enlazada%0A%20%20%20%20revrotate_a%28%26head,%200%29%3B%0A%0A%20%20%20%20//%20Imprimimos%20la%20lista%20para%20verificar%20si%20la%20funci%C3%B3n%20tuvo%20efecto%0A%20%20%20%20t_list%20*temp%20%3D%20head%3B%0A%20%20%20%20while%20%28temp%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%22,%20temp-%3Edata%29%3B%0A%20%20%20%20%20%20%20%20temp%20%3D%20temp-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%0A%20%20%20%20//%20Liberamos%20la%20memoria%20de%20la%20lista%20enlazada%0A%20%20%20%20free%28head%29%3B%0A%20%20%20%20free%28second%29%3B%0A%20%20%20%20free%28third%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
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

void	choose(t_list **headA)
{
	if (ft_count_list(*headA) == 3)
		ft_algo_3(headA);
}

void	multarg(int argc, char **argv)
{
	t_list	*head;
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
	choose(&head);
	aux = head;
	while (head != NULL)
	{
		printf("%d\n", head->data);
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
