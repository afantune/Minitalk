/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:04:12 by afantune          #+#    #+#             */
/*   Updated: 2025/03/12 13:56:01 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
ssize_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_error(const char *message);
int		ft_atoi(const char *str);
void	ft_kill(pid_t pid, int signal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
