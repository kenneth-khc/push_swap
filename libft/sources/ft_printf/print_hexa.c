/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:57:51 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_hexadecimal(unsigned int nbr, t_format *format)
{
	char	*string;

	string = itohexa(nbr, format);
	resolve_format_hexa(nbr, format);
	print_string_hexa(string, format);
	free(string);
}

void	resolve_format_hexa(unsigned int nbr, t_format *format)
{
	if (nbr == 0)
	{
		format->is_zero = true;
		format->hash = false;
	}
	if (format->precision && format->pad_zeroes)
		format->pad_zeroes = false;
	if (format->left_align && format->pad_zeroes)
		format->pad_zeroes = false;
	if (format->pad_zeroes)
		format->pad = '0';
	else
		format->pad = ' ';
	if (format->precise_len > format->width_length)
		format->width_length = 0;
	if (format->hash)
	{
		if (!format->uppercase)
			format->prefix = "0x";
		else if (format->uppercase)
			format->prefix = "0X";
	}
}

void	print_string_hexa(char *string, t_format *format)
{
	int	digits;
	int	i;

	i = 0;
	digits = ft_strlen(string);
	if (format->hash)
		digits += 2;
	if (!format->left_align)
		digits = print_width_hexa(format, digits);
	digits = print_precision_hexa(format, digits);
	while (string[i] && i < digits)
	{	
		if (format->is_zero && format->precision && format->precise_len == 0)
			break ;
		ft_putchar(string[i]);
		format->total_len++;
		i++;
	}
	if (format->left_align && format->width)
		digits = print_width_hexa(format, digits);
}

int	print_width_hexa(t_format *format, int digits)
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
		format->total_len++;
		padding--;
	}
	return (digits);
}

int	print_precision_hexa(t_format *format, int digits)
{
	int	i;

	i = digits;
	if (format->hash)
	{
		ft_putstr(format->prefix);
		format->total_len += 2;
		digits += 2;
	}
	while (i < format->precise_len)
	{
		ft_putchar('0');
		format->total_len++;
		digits++;
		i++;
	}
	return (digits);
}
