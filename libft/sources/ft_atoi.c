/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:58:54 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:58:01 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Atoi converts a string to integer
 * It checks for whitespaces, one + or - sign, and then digits
 * It is different from the 42 version in Piscine that checks for multiple signs 
**/

#include "../includes/libft.h"
#define POSITIVE 1
#define NEGATIVE -1

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = POSITIVE;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = NEGATIVE;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
