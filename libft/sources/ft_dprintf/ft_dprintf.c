/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:31:40 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:38:21 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"

int	d_check_type(char *string, int i, t_dformat *format, va_list ap)
{
	if (string[i] == 'c')
		d_print_char(va_arg(ap, int), format);
	if (string[i] == 's')
		d_print_string(va_arg(ap, char *), format);
	if (string[i] == 'p')
		d_print_pointer(va_arg(ap, void *), format);
	if (string[i] == 'd' || string[i] == 'i')
		d_print_integer(va_arg(ap, int), format);
	if (string[i] == 'u')
		d_print_uninteger(va_arg(ap, unsigned int), format);
	if (string[i] == 'x' || string[i] == 'X')
	{
		if (string[i] == 'X')
			format->uppercase = true;
		d_print_hexadecimal(va_arg(ap, unsigned int), format);
	}
	i += 1;
	return (i);
}

int	d_check_format(char *string, int i, t_dformat *format, va_list ap)
{
	if (string[i] == '%')
	{
		ft_putchar_fd('%', format->fd);
		format->total_len += 1;
		i++;
		return (i);
	}
	if (isflag(string[i]))
		i = d_check_flags(string, i, format);
	if (iswidth(string[i]))
		i = d_check_width(string, i, format);
	if (isprecision(string[i]))
		i = d_check_precision(string, i, format);
	if (istype(string[i]))
		i = d_check_type(string, i, format, ap);
	return (i);
}

int	d_parse_string(char *string, va_list ap, int fd)
{
	int			i;
	t_dformat	*format;
	int			printed_chars;

	i = 0;
	format = d_initialize_struct();
	format->fd = fd;
	while (string[i])
	{	
		if (string[i] != '%')
		{
			ft_putchar_fd(string[i], format->fd);
			format->total_len++;
			i++;
		}
		if (string[i] == '%')
		{
			i = d_check_format(string, i + 1, format, ap);
			d_reset_format(format);
		}
	}
	printed_chars = format->total_len;
	free(format);
	return (printed_chars);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*string;
	int		printed_chars;

	va_start (ap, format);
	string = (char *) format;
	printed_chars = d_parse_string(string, ap, fd);
	va_end(ap);
	return (printed_chars);
}
