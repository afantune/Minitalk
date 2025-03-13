/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:40:11 by afantune          #+#    #+#             */
/*   Updated: 2025/03/12 13:56:35 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(const char *message)
{
	if (!message)
		message = "Unknown error";
	if (ft_strlen(message) > 0 && (ft_strlen(message) < 7 || ft_strncmp(message,
				"Error: ", 7) != 0))
		write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}
