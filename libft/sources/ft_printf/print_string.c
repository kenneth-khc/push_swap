/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:33:41 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:19 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_string(char *string, t_format *format)
{
	int	i;
	int	str_len;

	i = 0;
	if (string == NULL)
	string = "(null)";
	str_len = ft_strlen(string);
	if (format->precision && format->precise_len < str_len)
		str_len = print_precision(string, format, str_len, i);
	if (format->width)
		print_width(string, format, str_len, i);
	else
	{
		while (i < str_len)
		{
			ft_putchar(string[i]);
			format->total_len++;
			i++;
		}
	}
}

void	print_width(char *string, t_format *format, int str_len, int i)
{
	int	padding;

	padding = format->width_length - str_len;
	if (!format->left_align)
	{
		while (padding > 0)
		{
			ft_putchar(' ');
			format->total_len++;
			padding--;
		}
	}
	while (i < str_len)
	{
		ft_putchar(string[i]);
		format->total_len++;
		i++;
	}
	while (padding > 0)
	{
		ft_putchar(' ');
		format->total_len++;
		padding--;
	}
}

int	print_precision(char *string, t_format *format, int str_len, int i)
{
	str_len = format->precise_len;
	if (format->precise_len == 0 && format->width)
	{
		print_width(string, format, str_len, i);
		format->width = false;
		return (str_len);
	}
	if (format->precise_len == 0)
		return (str_len);
	return (str_len);
}
