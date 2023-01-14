/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:20:19 by inigo             #+#    #+#             */
/*   Updated: 2023/01/14 16:08:23 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *headA, int i)
{
	int	temp;
	if (headA)
	{
		if (headA -> next)
		{
			temp = headA -> next -> data;
			headA -> next -> data = headA -> data;
			headA -> data = temp;
			if (i == 0)
				write(1, "sa\n", 3);
		}
	}
}

void	swap_b(t_list *headB, int i)
{
	int	temp;
	if (headB)
	{
		if (headB -> next)
		{
			temp = headB -> next -> data;
			headB -> next -> data = headB -> data;
			headB -> data = temp;
			if (i == 0)
				write(1, "sb\n", 3);
		}
	}
}

void	ss(t_list *headA, t_list *headB)
{
	swap_a(headA, 1);
	swap_b(headB, 1);
	//si uno/ambos no se han podido hacer printeo ss y arriba siempre debo imprimir aunque no se pueda?
}

void	push_a(t_list **headA, t_list **headB)
{
	t_list	*temp;
	
	if (*headA && *headB)
	{
		temp = *headB;
		*headB = temp -> next;
		temp -> next = *headA;
		*headA = temp;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **headA, t_list **headB)
{
	t_list	*temp;
	
	if (*headA && *headB)
	{
		temp = *headA;
		*headA = temp -> next;
		temp -> next = *headB;
		*headB = temp;
		write(1, "pb\n", 3);
	}
}

void	rotate_a(t_list **headA, int i)
{
	t_list	*temp;
	
	temp = *headA;
	if (*headA)
	{
		while (temp -> next)
			temp =  temp -> next;
		temp -> next = *headA;
		temp = *headA;
		*headA = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **headB, int i)
{
	t_list	*temp;
	
	temp = *headB;
	if (*headB)
	{
		while (temp -> next)
			temp =  temp -> next;
		temp -> next = *headB;
		temp = *headB;
		*headB = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **headA, t_list **headB)
{
	rotate_a(headA, 1);
	rotate_b(headB, 1);
	//si uno/ambos no se han podido hacer printeo ss y arriba siempre debo imprimir aunque no se pueda?
}

void	revrotate_a(t_list **headA, int i)
{
	t_list	*temp;
	
	temp = *headA;
	if (*headA)
	{
		while (temp -> next -> next)
			temp =  temp -> next;
		temp -> next -> next = *headA;
		*headA = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rra\n", 4);
	}
}

void	revrotate_b(t_list **headB, int i)
{
	t_list	*temp;
	
	temp = *headB;
	if (*headB)
	{
		while (temp -> next -> next)
			temp =  temp -> next;
		temp -> next -> next = *headB;
		*headB = temp -> next;
		temp -> next = NULL;
		if (i == 0)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **headA, t_list **headB)
{
	revrotate_a(headA, 1);
	revrotate_b(headB, 1);
	//si uno/ambos no se han podido hacer printeo ss y arriba siempre debo imprimir aunque no se pueda?
}

//solo funcionan los ss /añadir \n a los writes
//https://pythontutor.com/visualize.html#code=%23include%20%3Cunistd.h%3E%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Atypedef%20struct%20s_list%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20data%3B%0A%20%20%20%20struct%20s_list%20%20%20%20*next%3B%0A%7D%20%20%20%20t_list%3B%0A%0Aint%20%20%20%20swap_a%28t_list%20*headA%29%0A%7B%0A%20%20%20%20int%20%20%20%20temp%3B%0A%20%20%20%20if%20%28headA%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28headA%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20headA%20-%3E%20next%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headA%20-%3E%20next%20-%3E%20data%20%3D%20headA%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headA%20-%3E%20data%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22sa%22,%202%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20%20%20%20swap_b%28t_list%20*headB%29%0A%7B%0A%20%20%20%20int%20%20%20%20temp%3B%0A%20%20%20%20if%20%28headB%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28headB%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20headB%20-%3E%20next%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headB%20-%3E%20next%20-%3E%20data%20%3D%20headB%20-%3E%20data%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20headB%20-%3E%20data%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22sb%22,%202%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20%20%20%20ss%28t_list%20*headA,%20t_list%20*headB%29%0A%7B%0A%20%20%20%20swap_a%28headA%29%3B%0A%20%20%20%20swap_b%28headB%29%3B%0A%20%20%20%20//si%20uno/ambos%20no%20se%20han%20podido%20hacer%20printeo%20ss%20y%20arriba%20siempre%20debo%20imprimir%20aunque%20no%20se%20pueda%3F%0A%7D%0A%0Avoid%20%20%20%20push_a%28t_list%20*headA,%20t_list%20*headB%29%0A%7B%0A%20%20%20%20if%20%28headA%20%26%26%20headB%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20headB%20-%3E%20next%20%3D%20headA%3B%0A%20%20%20%20%20%20%20%20headA%20%3D%20headB%3B%0A%20%20%20%20%20%20%20%20write%281,%20%22pa%22,%202%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20%20%20%20push_b%28t_list%20*headA,%20t_list%20*headB%29%0A%7B%0A%20%20%20%20if%20%28headA%20%26%26%20headB%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20headA%20-%3E%20next%20%3D%20headB%3B%0A%20%20%20%20%20%20%20%20headB%20%3D%20headA%3B%0A%20%20%20%20%20%20%20%20write%281,%20%22pa%22,%202%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20%20%20%20rotate_b%28t_list%20*headB%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20*temp%3B%0A%20%20%20%20%0A%20%20%20%20temp%20%3D%20headB%3B%0A%20%20%20%20if%20%28headB%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20while%20%28temp%20-%3E%20next%29%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20%20temp%20-%3E%20next%3B%0A%20%20%20%20%20%20%20%20temp%20-%3E%20next%20%3D%20headB%3B%0A%20%20%20%20%20%20%20%20headB%20-%3E%20next%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20write%281,%20%22rb%22,%202%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20//%20Crea%20los%20nodos%20de%20la%20lista%20A%0A%20%20%20%20t_list%20*node1%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node1-%3Edata%20%3D%201%3B%0A%0A%20%20%20%20t_list%20*node2%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node2-%3Edata%20%3D%202%3B%0A%20%20%20%20node1-%3Enext%20%3D%20node2%3B%0A%0A%20%20%20%20t_list%20*node3%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node3-%3Edata%20%3D%203%3B%0A%20%20%20%20node2-%3Enext%20%3D%20node3%3B%0A%20%20%20%20node3-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20//headA%20apunta%20al%20primer%20nodo%20de%20la%20lista%0A%20%20%20%20t_list%20*headA%20%3D%20node1%3B%0A%0A%20%20%20%20//%20Crea%20los%20nodos%20de%20la%20lista%20B%0A%20%20%20%20t_list%20*node4%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node4-%3Edata%20%3D%204%3B%0A%0A%20%20%20%20t_list%20*node5%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node5-%3Edata%20%3D%205%3B%0A%20%20%20%20node4-%3Enext%20%3D%20node5%3B%0A%0A%20%20%20%20t_list%20*node6%20%3D%20%28t_list*%29malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20node6-%3Edata%20%3D%206%3B%0A%20%20%20%20node5-%3Enext%20%3D%20node6%3B%0A%20%20%20%20node6-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20//headB%20apunta%20al%20primer%20nodo%20de%20la%20lista%0A%20%20%20%20t_list%20*headB%20%3D%20node4%3B%0A%20%20%20%20ss%28headA,headB%29%3B%0A%20%20%20%20//push_b%28headA,%20headB%29%3B%0A%20%20%20%20rotate_b%28headB%29%3B%0A%20%20%20%20%0A%20%20%20%20//%20Recorre%20y%20muestra%20la%20lista%20A%0A%20%20%20%20printf%28%22Lista%20A%3A%20%22%29%3B%0A%20%20%20%20for%20%28t_list%20*current%20%3D%20headA%3B%20current%20!%3D%20NULL%3B%20current%20%3D%20current-%3Enext%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%22,%20current-%3Edata%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%0A%20%20%20%20//%20Recorre%20y%20muestra%20la%20lista%20B%0A%20%20%20%20printf%28%22Lista%20B%3A%20%22%29%3B%0A%20%20%20%20for%20%28t_list%20*current%20%3D%20headB%3B%20current%20!%3D%20NULL%3B%20current%20%3D%20current-%3Enext%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%22,%20current-%3Edata%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false