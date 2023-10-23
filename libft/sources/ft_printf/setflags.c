/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:24 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	check_flags(char *string, int i, t_format *format)
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

int	check_width(char *string, int i, t_format *format)
{
	format->width = true;
	format->width_length = ft_atoi(&string[i]);
	while (ft_isdigit(string[i]))
		i++;
	return (i);
}

int	check_precision(char *string, int i, t_format *format)
{
	format->precision = true;
	i++;
	format->precise_len = ft_atoi(&string[i]);
	while (ft_isdigit(string[i]))
		i++;
	return (i);
}
