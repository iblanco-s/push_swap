/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:43:23 by iblanco-          #+#    #+#             */
/*   Updated: 2023/01/07 19:04:26 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;
	int	len;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (i < len && c == s[i])
			i++;
		j = i;
		while (i < len && c != s[i])
			i++;
		if (i > j)
			count++;
	}
	return (count);
}

char	**ft_copy(char **strings, char *temp, char c, char const *s)
{
	int	i[5];

	i[4] = 0;
	while (i[4] < 4)
		i[i[4]] = 0;
	i[4] = ft_strlen(s);
	while (i[0] < i[4])
	{
		while (i[0] < i[4] && c == s[i[0]])
			i[0]++;
		while (i[0] < i[4] && c != s[i[0]])
			temp[i[1]++] = s[i[0]++];
		if (i[1] > 0 && (i[2] + 1)< (ft_count(s, c) + 1))
		{
			temp[i[1]] = '\0';
			strings[i[2] + 1] = malloc(sizeof(char) * (ft_strlen(&temp[i[3]]) + 1));
			if (!strings[i[2] + 1])
				error();
			ft_strlcpy(strings[i[2] + 1], &temp[i[3]], ft_strlen(&temp[i[3]]) + 1);
			i[2]++;
			i[3] = i[1];
		}
	}
	strings[i[2] + 1] = NULL;
	return (strings);
}

char	**ft_mod_split(char const *s, char c)
{
	char	*temp;
	char	**strings;

	if (s == NULL)
		error();
	temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s)
		error();
	strings = (char **)malloc((sizeof(char *) * (ft_count(s, c) + 2)));
	if (!strings)
	{
		free(temp);
		error();
	}
	strings[0] = malloc(1);
	strings[0] = NULL;
	ft_copy(strings, temp, c, s);
	free(temp);
	return (strings);
}
