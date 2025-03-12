/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:35:14 by afantune          #+#    #+#             */
/*   Updated: 2025/03/12 13:25:40 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/minitalk.h"

void	ft_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_error("Error: Invalid PID\n");
	}
}
