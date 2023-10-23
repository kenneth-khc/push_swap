/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:04:00 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

void	d_print_char(int c, t_dformat *format)
{
	int		padding;

	padding = format->width_length - 1;
	if (format->width)
	{
		if (!format->left_align)
		{
			while (padding-- > 0)
			{
				ft_putchar_fd(' ', format->fd);
				format->total_len++;
			}
		}
		ft_putchar_fd(c, format->fd);
		format->total_len += 1;
		while (padding-- > 0)
		{
			ft_putchar_fd(' ', format->fd);
			format->total_len++;
		}
		return ;
	}
	ft_putchar_fd(c, format->fd);
	format->total_len += 1;
}
