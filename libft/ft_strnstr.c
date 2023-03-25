/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:18:19 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/01 08:43:24 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_nh(const char *haystack, const char *needle, size_t index,
size_t len)
{
	size_t	i;

	i = 0;
	while (haystack[index] && needle[i] && index < len)
	{
		if (haystack[index] != needle[i])
			return (0);
		i++;
		index++;
	}
	if (index == len && needle[i])
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
			if (check_nh(haystack, needle, i, len))
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
