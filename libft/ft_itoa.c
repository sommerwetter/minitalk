/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:23:15 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/24 10:35:00 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	reverse(long n_cpy)
{
	long	n_r;
	int		nbr;

	n_r = 0;
	nbr = 0;
	while (n_cpy > 0)
	{
		nbr = n_cpy % 10;
		n_r = (n_r * 10) + nbr;
		n_cpy /= 10;
	}
	return (n_r);
}

static	void	strnbr(int n, long n_r, char *str)
{
	size_t	i;

	i = 0;
	if (n < 0)
		str[i++] = '-';
	if (n == 0)
		str[i++] = '0';
	while (n_r > 0)
	{
		str[i] = (n_r % 10) + '0';
		n_r /= 10;
		i++;
	}
	while ((n % 10 == 0) && n != 0)
	{
		str[i] = '0';
		i++;
		n /= 10;
	}
	str[i] = 0;
}

char	*ft_itoa(int n)
{
	int			count;
	long		n_r;
	long		n_cpy;
	char		*str;

	count = 0;
	n_cpy = n;
	if (n_cpy < 0)
		n_cpy *= (-1);
	n_r = reverse(n_cpy);
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		count++;
	}
	if (n == 0 || n < 0)
		count++;
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	strnbr(n, n_r, str);
	return (str);
}
