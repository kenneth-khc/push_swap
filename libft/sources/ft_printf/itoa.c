/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:05:32 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:06 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	num_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	convert(char *str, long n, size_t len)
{
	unsigned int	i;
	int				neg;

	i = 0;
	neg = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		len -= 1;
		neg = 1;
		n *= -1;
	}
	while (i < len)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[len] = '\0';
}

static void	convert_unint(char *str, long n, size_t len)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		str[0] = '0';
	while (i < len)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[len] = '\0';
}

char	*itoa(int n)
{
	char			*str;

	str = (char *)malloc((num_len(n) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	convert(str, n, num_len(n));
	return (str);
}

char	*uitoa(unsigned int n)
{
	char			*str;

	str = (char *)malloc((num_len(n) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	convert_unint(str, n, num_len(n));
	return (str);
}
