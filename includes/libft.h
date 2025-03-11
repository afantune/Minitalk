/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:04:12 by afantune          #+#    #+#             */
/*   Updated: 2025/03/11 13:13:43 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <stdlib.h>

ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);

#endif
