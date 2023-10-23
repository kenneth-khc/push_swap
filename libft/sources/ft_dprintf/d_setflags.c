/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_setflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

int	d_check_flags(char *string, int i, t_dformat *format)
{
	while (isflag(string[i]))
	{
		if (string[i] == '-')
			format->left_align = true;
		if (string[i] == '0')
			format->pad_zeroes = true;
		if (string[i] == '#')
			format->hash = true;
		if (string[i] == ' ')
			format->space = true;
		if (string[i] == '+')
			format->plus = true;
		i++;
	}
	return (i);
}

int	d_check_width(char *string, int i, t_dformat *format)
{
	format->width = true;
	format->width_length = ft_atoi(&string[i]);
	while (ft_isdigit(string[i]))
		i++;
	return (i);
}

int	d_check_precision(char *string, int i, t_dformat *format)
{
	format->precision = true;
	i++;
	format->precise_len = ft_atoi(&string[i]);
	while (ft_isdigit(string[i]))
		i++;
	return (i);
}
