/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_struct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:50:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:37:51 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

t_dformat	*d_initialize_struct(void)
{
	t_dformat	*format;

	format = (t_dformat *)malloc((sizeof(t_dformat)));
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

void	d_reset_format(t_dformat *format)
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
