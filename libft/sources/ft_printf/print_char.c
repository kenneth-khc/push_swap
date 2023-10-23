/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:04:00 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:09 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_char(int c, t_format *format)
{
	int		padding;

	padding = format->width_length - 1;
	if (format->width)
	{
		if (!format->left_align)
		{
			while (padding-- > 0)
			{
				ft_putchar(' ');
				format->total_len++;
			}
		}
		ft_putchar(c);
		format->total_len += 1;
		while (padding-- > 0)
		{
			ft_putchar(' ');
			format->total_len++;
		}
		return ;
	}
	ft_putchar(c);
	format->total_len += 1;
}
