/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:32 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/04 14:44:10 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	multarg(int argc, char **argv);
int		main(int argc, char **argv);
int		ft_count(char const *s, char c);
char	**ft_copy(char **strings, char *temp, char c, char const *s);
char	**ft_split(char const *s, char c);

#endif
