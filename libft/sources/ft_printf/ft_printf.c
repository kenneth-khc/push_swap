/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:31:40 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:55:38 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	check_type(char *string, int i, t_format *format, va_list ap)
{
	if (string[i] == 'c')
		print_char(va_arg(ap, int), format);
	if (string[i] == 's')
		print_string(va_arg(ap, char *), format);
	if (string[i] == 'p')
		print_pointer(va_arg(ap, void *), format);
	if (string[i] == 'd' || string[i] == 'i')
		print_integer(va_arg(ap, int), format);
	if (string[i] == 'u')
		print_uninteger(va_arg(ap, unsigned int), format);
	if (string[i] == 'x' || string[i] == 'X')
	{
		if (string[i] == 'X')
			format->uppercase = true;
		print_hexadecimal(va_arg(ap, unsigned int), format);
	}
	i += 1;
	return (i);
}

int	check_format(char *string, int i, t_format *format, va_list ap)
{
	if (string[i] == '%')
	{
		ft_putchar('%');
		format->total_len += 1;
		i++;
		return (i);
	}
	if (isflag(string[i]))
		i = check_flags(string, i, format);
	if (iswidth(string[i]))
		i = check_width(string, i, format);
	if (isprecision(string[i]))
		i = check_precision(string, i, format);
	if (istype(string[i]))
		i = check_type(string, i, format, ap);
	return (i);
}

int	parse_string(char *string, va_list ap)
{
	int			i;
	t_format	*format;
	int			printed_chars;

	i = 0;
	format = initialize_struct();
	while (string[i])
	{	
		if (string[i] != '%')
		{
			ft_putchar(string[i]);
			format->total_len++;
			i++;
		}
		if (string[i] == '%')
		{
			i = check_format(string, i + 1, format, ap);
			reset_format(format);
		}
	}
	printed_chars = format->total_len;
	free(format);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*string;
	int		printed_chars;

	va_start (ap, format);
	string = (char *) format;
	printed_chars = parse_string(string, ap);
	va_end(ap);
	return (printed_chars);
}
