/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:32 by iblanco-          #+#    #+#             */
/*   Updated: 2023/03/09 16:31:11 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str, char **argv, t_list *head);
void		multarg(int argc, char **argv);
void		error(void);
int			main(int argc, char **argv);
int			ft_count(char const *s, char c);
char		**ft_copy(char **strings, char *temp, char c, char const *s);
char		**ft_mod_split(char const *s, char c);
int			ft_strlen(const char *a);
size_t		ft_strlcpy(char *dest, const char *src, size_t len);
void		mult_free(char **argv);
void		doubles(t_list *head);
void		err_check(char **argv);
void		free_err_check(char **argv);
void		free_list(t_list *head);
void		atoi_error(char **argv, t_list *head);
void 		rrr(t_list **headA, t_list **headB);
void		revrotate_b(t_list **headB, int i);
void		revrotate_a(t_list **headA, int i);
void		rr(t_list **headA, t_list **headB);
void		rotate_b(t_list **headB, int i);
void		rotate_a(t_list **headA, int i);
void		ss(t_list *headA, t_list *headB);
void		swap_b(t_list *headB, int i);
void		swap_a(t_list *headA, int i);
void		push_a(t_list **headA, t_list **headB);
void		push_b(t_list **headA, t_list **headB);
int			ft_count_list(t_list *head);
void		ft_algo_3(t_list **headA);
void		choose(t_list **headA);

#endif
