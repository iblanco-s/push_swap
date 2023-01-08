/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:32 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/07 18:35:50 by inigo            ###   ########.fr       */
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

int			ft_atoi(const char *str);
void		multarg(int argc, char **argv);
void		error(void);
int			main(int argc, char **argv);
int			ft_count(char const *s, char c);
char		**ft_copy(char **strings, char *temp, char c, char const *s);
char		**ft_mod_split(char const *s, char c);
int			ft_strlen(const char *a);
size_t		ft_strlcpy(char *dest, const char *src, size_t len);

#endif