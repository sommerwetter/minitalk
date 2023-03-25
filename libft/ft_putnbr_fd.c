/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:06:53 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/31 17:43:04 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	long	reversenbr(int nb)
{
	int		b;
	long	r;
	long	nb2;

	r = 0;
	b = 0;
	nb2 = nb;
	if (nb2 < 0)
		nb2 *= -1;
	while (nb2 > 0)
	{
		b = (nb2 % 10);
		r = r * 10 + b;
		nb2 /= 10;
	}
	return (r);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int			b;
	long		a;

	a = reversenbr(nb);
	b = 0;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
		write(fd, "-", 1);
	while (a > 0)
	{
		b = (a % 10) + '0';
		write (fd, &b, 1);
		a /= 10;
	}
	while ((nb % 10) == 0 && nb != 0)
	{
		write(fd, "0", 1);
		nb = nb / 10;
	}
}
