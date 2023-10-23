/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isformat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:56:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:03 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

bool	isflag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (true);
	return (false);
}

bool	iswidth(char c)
{
	if (c >= '1' && c <= '9')
		return (true);
	return (false);
}

bool	isprecision(char c)
{
	if (c == '.')
		return (true);
	return (false);
}

bool	istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (true);
	return (false);
}
