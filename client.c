/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:47:04 by marmoral          #+#    #+#             */
/*   Updated: 2023/03/27 21:21:18 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

/*
	Message to the Client from the server.
*/
static void	server_sig(int n)
{
	if (n == SIGUSR1)
		ft_putstr_fd("Message received!", 1);
}

/*
	Sends letters to the server. This is done by taking each letter and sending each
	bit value (either 1 or 0) to the server as Signals (sigusr1 = 1 and sigusr = 0)
	by bitwise shifting the value by 7 (i_bit starting value) we move the leftmost
	value all the way to the right (becomes the rightmost value) and by the '&' we 
	compare it to the value of 1 which if the rightmost value number is then it will
	return 1 or 0 if not.
*/
/*
 	By reducing the amount of shifts (reducing i_bit) we move each
	value (after the leftmost value) up to the righmost place.
*/
static void	c2b(unsigned int c, int pid)
{
	int	i_bit;

	i_bit = 7;
	while (i_bit >= 0)
	{
		if ((c >> i_bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i_bit--;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					i_byte;
	int					pid;

	if (argc == 3)
	{
		i_byte = 0;
		pid = ft_atoi(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &server_sig;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_putstr_fd("Error with SIGUSR1\n", 1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_putstr_fd("Error with SIGUSR2\n", 1);
		while (argv[2][i_byte])
			c2b(argv[2][i_byte++], pid);
		c2b('\0', pid);
		return (0);
	}
	else
	{
		ft_putendl_fd("ERROR - invalid or not enough variables", 1);
		return (1);
	}
}
