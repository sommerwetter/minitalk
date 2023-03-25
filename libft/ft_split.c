/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:48:39 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/24 11:24:40 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	save(char **split, const char *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	count;

	i = 0;
	x = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			split[x] = ft_substr(s, (i - (count - 1)), count);
			x++;
			count = 0;
		}
		i++;
	}
	split[x] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	x;
	char	**split;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			x++;
		i++;
	}
	split = malloc(sizeof(char *) * (x + 1));
	if (!split)
		return (NULL);
	save(split, s, c);
	return (split);
}
