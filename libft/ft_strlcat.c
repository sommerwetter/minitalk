/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:54:34 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/28 21:38:39 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;
	size_t	ans;

	i = 0;
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	ans = 0;
	if (size < dst_l)
	{
		ans = src_l + size;
		return (ans);
	}
	else
		ans = dst_l + src_l;
	while (src[i] && dst_l < size - 1 && size > 0)
	{
		dst[dst_l] = src[i];
		dst_l++;
		i++;
	}
	dst[dst_l] = 0;
	return (ans);
}
