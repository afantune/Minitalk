/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:45 by afantune          #+#    #+#             */
/*   Updated: 2025/03/17 13:28:57 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static pid_t	pid;
	static char		c;
	static int		bits;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signal == SIGUSR2)
		c |= (128 >> bits);
	else if (signal == SIGUSR1)
		c &= ~(128 >> bits);
	if (++bits == 8)
	{
		bits = 0;
		if (c == '\0' && write(STDOUT_FILENO, "\n", 1))
		{
			bits = 0;
			c = 0;
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("Error: Sigaction failed!");
	while (1)
		pause();
	return (0);
}
