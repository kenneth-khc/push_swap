/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_isformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:56:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:13:59 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

bool	d_isflag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (true);
	return (false);
}

bool	d_iswidth(char c)
{
	if (c >= '1' && c <= '9')
		return (true);
	return (false);
}

bool	d_isprecision(char c)
{
	if (c == '.')
		return (true);
	return (false);
}

bool	d_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (true);
	return (false);
}
