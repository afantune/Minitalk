/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:21:29 by afantune          #+#    #+#             */
/*   Updated: 2024/10/30 12:28:17 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_strlen(const char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
