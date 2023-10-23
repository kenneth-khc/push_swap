/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:23:19 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:36:21 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

void	d_print_integer(int nbr, t_dformat *format)
{
	char	*string;

	d_resolve_format(nbr, format);
	string = itoa(nbr);
	d_print_string_int(string, format);
	free (string);
}

void	d_resolve_format(int nbr, t_dformat *format)
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
	if (format->space && format->positive)
		format->prefix = " ";
	else
		format->prefix = "+";
	if (format->precise_len > format->width_length)
		format->width_length = 0;
}

void	d_print_string_int(char *string, t_dformat *format)
{
	int	digits;
	int	i;

	i = 0;
	digits = ft_strlen(string);
	if (!format->positive || format->space || format->plus)
		format->sign = 1;
	if (!format->left_align)
		digits = d_print_width_int(format, digits);
	digits = d_print_precision_int(format, digits);
	while (string[i] && i < digits)
	{	
		if (format->is_zero && format->precision && format->precise_len == 0)
			break ;
		ft_putchar_fd(string[i], format->fd);
		format->total_len++;
		i++;
	}
	if (format->left_align && format->width)
		digits = d_print_width_int(format, digits);
}

int	d_print_width_int(t_dformat *format, int digits)
{
	int	padding;

	if (format->is_zero && format->precision && format->precise_len == 0)
		digits -= 1;
	padding = format->width_length - format->sign - digits;
	if (format->precise_len > digits)
		padding -= format->precise_len - digits;
	if (!format->positive && format->pad_zeroes)
	{
		ft_putchar_fd('-', format->fd);
		format->total_len++;
		digits++;
	}
	while (padding > 0)
	{
		ft_putchar_fd(format->pad, format->fd);
		format->total_len++;
		padding--;
	}
	return (digits);
}

int	d_print_precision_int(t_dformat *format, int digits)
{
	if (!format->positive && !format->pad_zeroes)
	{
		ft_putchar_fd('-', format->fd);
		format->total_len++;
	}
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
