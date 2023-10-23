/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:23:52 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an integer to a string
 * This only handles base10 numbers
 *
 * Allocate the space needed by counting the number of digits in the number
 * Use modulo to get the last digit of the number and assign it into the string
**/

#include "../includes/libft.h"
#define POSITIVE 1
#define NEGATIVE -1

static size_t	get_number_length(long number)
{
	size_t	len;

	len = 0;
	if (number == 0)
		len = 1;
	if (number < 0)
	{
		number *= -1;
		len += 1;
	}
	while (number > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static void	convert_to_string(char *str, long number, size_t len)
{
	int	sign;

	sign = POSITIVE;
	if (number < 0)
	{
		sign = NEGATIVE;
		number *= -1;
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = number % 10 + '0';
		number /= 10;
	}
	if (sign == NEGATIVE)
		str[0] = '-';
}

char	*ft_itoa(int number)
{
	char	*str;
	size_t	digits;

	digits = get_number_length(number);
	str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	convert_to_string(str, number, digits);
	return (str);
}
