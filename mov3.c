/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:43:24 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/22 17:34:22 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	//si uno/ambos no se han podido hacer printeo ss 
	//y arriba siempre debo imprimir aunque no se pueda?

void	rrr(t_list **headA, t_list **headB)
{
	revrotate_a(headA, 1);
	revrotate_b(headB, 1);
	write(1, "rrr\n", 4);
}

//solo funcionan los ss /añadir \n a los writes
