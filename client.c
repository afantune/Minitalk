/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:56 by afantune          #+#    #+#             */
/*   Updated: 2025/03/13 15:12:12 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (128 >> bit))
			ft_kill(pid, SIGUSR2);
		else
			ft_kill(pid, SIGUSR1);
		bit++;
		usleep(42);
	}
}

static void	send_message(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_error("Usage: ./client <PID> <message>");
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		ft_error("Invalid PID");
	send_message(pid, argv[2]);
	return (0);
}
