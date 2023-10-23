/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_uninteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:19:13 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

void	d_print_uninteger(int nbr, t_dformat *format)
{
	char	*string;

	d_resolve_format_unint(nbr, format);
	string = d_uitoa(nbr);
	d_print_string_unint(string, format);
	free (string);
}

void	d_resolve_format_unint(unsigned int nbr, t_dformat *format)
{
	if (nbr >= 0)
		format->positive = true;
	if (nbr == 0)
		format->is_zero = true;
	if (format->plus && format->space)
		format->space = false;
	if (format->precision && format->pad_zeroes)
		format->pad_zeroes = false;
	if (format->left_align && format->pad_zeroes)
		format->pad_zeroes = false;
	if (format->pad_zeroes)
		format->pad = '0';
	else
		format->pad = ' ';
	if (format->space)
		format->prefix = " ";
	if (format->precise_len > format->width_length)
		format->width_length = 0;
}

void	d_print_string_unint(char *string, t_dformat *format)
{
	int	digits;
	int	i;

	i = 0;
	digits = ft_strlen(string);
	if (!format->left_align)
		digits = d_print_width_unint(format, digits);
	digits = d_print_precision_unint(format, digits);
	while (string[i] && i < digits)
	{	
		if (format->is_zero && format->precision && format->precise_len == 0)
			break ;
		ft_putchar_fd(string[i], format->fd);
		format->total_len++;
		i++;
	}
	if (format->left_align && format->width)
		digits = d_print_width_unint(format, digits);
}

int	d_print_width_unint(t_dformat *format, int digits)
{
	int	padding;

	if (format->is_zero && format->precision && format->precise_len == 0)
		digits -= 1;
	padding = format->width_length - digits;
	if (format->precise_len > digits)
		padding -= format->precise_len - digits;
	while (padding > 0)
	{
		ft_putchar_fd(format->pad, format->fd);
		padding--;
		format->total_len++;
	}
	return (digits);
}

int	d_print_precision_unint(t_dformat *format, int digits)
{
	if ((format->space || format->plus) && format->positive)
	{
		ft_putstr_fd(format->prefix, format->fd);
		format->total_len++;
		digits++;
	}
	while (digits < format->precise_len)
	{
		ft_putchar_fd('0', format->fd);
		format->total_len++;
		digits++;
	}
	return (digits);
}
