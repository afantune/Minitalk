/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:45 by afantune          #+#    #+#             */
/*   Updated: 2025/03/12 14:06:20 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void    ft_bin_to_char(int signal, char *c)
{
    if (signal == SIGUSR1)
        *c = (*c << 1) | 1;
    else if (signal == SIGUSR2)
        *c <<= 1;
}

void    sig_handler(int signal, siginfo_t *info, void *context)
{
    static int              pid = 0;
    static char             c = 0;
    static int              bits = 0;

    (void)context;
    if (pid != 0 && pid != info->si_pid)
        return ;
    if (pid == 0)
        pid = info->si_pid;
    ft_bin_to_char(signal, &c);
    if (++bits == 8)
    {
        bits = 0;
        if (c == '\0')
        {
            kill(pid, SIGUSR1);
            pid = 0;
            return ;
        }
        write(1, &c, 1);
        c = 0;
    }
    kill(pid, SIGUSR2);
}

int	main(void)
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        ft_error("Error: Sigaction failed!");
    while (1)
        pause();
    return (0);
}

