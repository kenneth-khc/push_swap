/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:57:51 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

void	d_print_hexadecimal(unsigned int nbr, t_dformat *format)
{
	char	*string;

	string = d_itohexa(nbr, format);
	d_resolve_format_hexa(nbr, format);
	d_print_string_hexa(string, format);
	free(string);
}

void	d_resolve_format_hexa(unsigned int nbr, t_dformat *format)
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

void	d_print_string_hexa(char *string, t_dformat *format)
{
	int	digits;
	int	i;

	i = 0;
	digits = ft_strlen(string);
	if (format->hash)
		digits += 2;
	if (!format->left_align)
		digits = d_print_width_hexa(format, digits);
	digits = d_print_precision_hexa(format, digits);
	while (string[i] && i < digits)
	{	
		if (format->is_zero && format->precision && format->precise_len == 0)
			break ;
		ft_putchar_fd(string[i], format->fd);
		format->total_len++;
		i++;
	}
	if (format->left_align && format->width)
		digits = d_print_width_hexa(format, digits);
}

int	d_print_width_hexa(t_dformat *format, int digits)
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
		format->total_len++;
		padding--;
	}
	return (digits);
}

int	d_print_precision_hexa(t_dformat *format, int digits)
{
	int	i;

	i = digits;
	if (format->hash)
	{
		ft_putstr_fd(format->prefix, format->fd);
		format->total_len += 2;
		digits += 2;
	}
	while (i < format->precise_len)
	{
		ft_putchar_fd('0', format->fd);
		format->total_len++;
		digits++;
		i++;
	}
	return (digits);
}
