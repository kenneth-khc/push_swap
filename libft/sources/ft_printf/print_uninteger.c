/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uninteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:19:13 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:21 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_uninteger(int nbr, t_format *format)
{
	char	*string;

	resolve_format_unint(nbr, format);
	string = uitoa(nbr);
	print_string_unint(string, format);
	free (string);
}

void	resolve_format_unint(unsigned int nbr, t_format *format)
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

void	print_string_unint(char *string, t_format *format)
{
	int	digits;
	int	i;

	i = 0;
	digits = ft_strlen(string);
	if (!format->left_align)
		digits = print_width_unint(format, digits);
	digits = print_precision_unint(format, digits);
	while (string[i] && i < digits)
	{	
		if (format->is_zero && format->precision && format->precise_len == 0)
			break ;
		ft_putchar(string[i]);
		format->total_len++;
		i++;
	}
	if (format->left_align && format->width)
		digits = print_width_unint(format, digits);
}

int	print_width_unint(t_format *format, int digits)
{
	int	padding;

	if (format->is_zero && format->precision && format->precise_len == 0)
		digits -= 1;
	padding = format->width_length - digits;
	if (format->precise_len > digits)
		padding -= format->precise_len - digits;
	while (padding > 0)
	{
		ft_putchar(format->pad);
		padding--;
		format->total_len++;
	}
	return (digits);
}

int	print_precision_unint(t_format *format, int digits)
{
	if ((format->space || format->plus) && format->positive)
	{
		ft_putstr(format->prefix);
		format->total_len++;
		digits++;
	}
	while (digits < format->precise_len)
	{
		ft_putchar('0');
		format->total_len++;
		digits++;
	}
	return (digits);
}
