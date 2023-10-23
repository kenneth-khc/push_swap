/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:50:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:29 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_format	*initialize_struct(void)
{
	t_format	*format;

	format = (t_format *)malloc((sizeof(t_format)));
	format->width = false;
	format->width_length = 0;
	format->left_align = false;
	format->pad_zeroes = false;
	format->pad = 0;
	format->precision = false;
	format->precise_len = 0;
	format->hash = false;
	format->space = false;
	format->plus = false;
	format->prefix = 0;
	format->positive = false;
	format->is_zero = false;
	format->sign = 0;
	format->uppercase = false;
	format->total_len = 0;
	return (format);
}

void	reset_format(t_format *format)
{
	format->width = false;
	format->width_length = 0;
	format->left_align = false;
	format->pad_zeroes = false;
	format->pad = 0;
	format->precision = false;
	format->precise_len = 0;
	format->hash = false;
	format->space = false;
	format->plus = false;
	format->prefix = 0;
	format->positive = false;
	format->is_zero = false;
	format->sign = 0;
	format->uppercase = false;
}
