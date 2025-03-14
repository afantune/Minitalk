/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:36:33 by afantune          #+#    #+#             */
/*   Updated: 2025/03/12 12:40:51 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_digit_lenght(unsigned int num)
{
	if (num < 10)
		return (1);
	return (1 + get_digit_lenght(num / 10));
}

static unsigned int	convert_to_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	size_t			digit_lenght;

	num = convert_to_positive(n);
	digit_lenght = get_digit_lenght(num);
	if (n < 0)
		digit_lenght += 1;
	str = malloc(digit_lenght + 1);
	if (!str)
		return (NULL);
	str[digit_lenght] = '\0';
	while (digit_lenght--)
	{
		str[digit_lenght] = '0' + (num % 10);
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
