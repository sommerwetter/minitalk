/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:13:05 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/02 03:43:59 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_sign(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		return (-1);
	return (1);
}

static	int	find_start(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] == '-' || str[n] == '+' || str[n] == ' ' || str[n] == '\n'
		|| str[n] == '\f' || str[n] == '\r' || str[n] == '\t' || str[n] == '\v')
	{
		if ((str[n] == '-' || str[n] == '+') && !ft_isdigit(str[n + 1]))
			return (-1);
		n++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int		x;
	int		nbr;
	long	result;

	nbr = 0;
	result = 0;
	x = find_start(str);
	if (x == -1)
		return (0);
	while (ft_isdigit(str[x]))
	{
		nbr = str[x] - '0';
		result = (result * 10) + nbr;
		x++;
	}
	return (check_sign(str) * result);
}
