/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:05:41 by marmoral          #+#    #+#             */
/*   Updated: 2023/03/25 16:40:33 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

/*
	I used for all the characters the type "unsigned int" because any ASCII
	value wont be negative and for the Unix Code and the extended ASCII Table
	the values of those characters exceed the maximum value a type "char" can
	hold. So in order to not overflow or for any unexpected behaviour I'm 
	using an "unsigned int" type which should me more than enough for those
	scenarios.
*/
int	new_putchar(unsigned int c)
{
	write(1, &c, 1);
	return (1);
}

/*
	The same principle as within the Client for the letter into bits trans-
	formation. Here we're "filling in" the bits into the variable "c" bit 
	by bit from left to right. By shifting it to the left once (adds a 0 on the
	rightmost place) and the operator "|" extracts that and changes it to 1 or 
	not depending on the signal received from the client.
*/
static void	b2c(int signal, unsigned int *c)
{
	if (signal == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signal == SIGUSR2)
		*c = *c << 1;
}

/*
	Static variables are only initialized once and the compiler will keep them
	until the end of the program. This allows us to 'save' it's value during a
	proccess if it's not changed by the function it was originally initialized.
*/
static void	client_sig(int signal, siginfo_t *info, void *context)
{
	static unsigned int		c;
	static int				i;
	static int				pid;

	(void)*context;
	if (pid == 0)
		pid = info->si_pid;
	b2c(signal, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			ft_putstr_fd("\nMessage: ", 1);
			pid = 0;
			return ;
		}
		new_putchar(c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" :Server PID\n", 1);
	ft_putstr_fd("Message: ", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = client_sig;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error with SIGUSR1\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error with SIGUSR2\n", 1);
	while (1)
		pause();
	return (0);
}
