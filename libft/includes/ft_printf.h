/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:19:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/libft.h"
# include <stdarg.h>

typedef struct s_format
{
	bool	width;
	int		width_length;

	bool	left_align;

	bool	pad_zeroes;
	char	pad;

	bool	precision;
	int		precise_len;

	bool	hash;
	bool	space;
	bool	plus;
	char	*prefix;

	bool	positive;
	bool	is_zero;
	int		sign;

	bool	uppercase;
	int		total_len;

}	t_format;

// printf.c

int			ft_printf(const char *format, ...);
t_format	*initialize_struct(void);
void		reset_format(t_format *format);
int			parse_string(char *string, va_list ap);
int			check_format(char *string, int i, t_format *format, va_list ap);
int			check_type(char *string, int i, t_format *format, va_list ap);
int			check_precision(char *string, int i, t_format *format);
int			check_width(char *string, int i, t_format *format);
int			check_flags(char *string, int i, t_format *format);
bool		isflag(char c);
bool		iswidth(char c);
bool		isprecision(char c);
bool		istype(char c);
void		ft_putstr(char *s);
void		ft_putchar(char c);

// %c

void		print_char(int c, t_format *format);

// %s

void		print_string(char *string, t_format *format);
void		print_width(char *string, t_format *format, int str_len, int i);
int			print_precision(char *string, t_format *format, int str_len, int i);

// %p

void		print_pointer(void *pointer, t_format *format);
char		*itohexa_ptr(uintptr_t address);
char		*reverse_string(char *string, int length);

// %d & %i

void		print_integer(int nbr, t_format *format);
void		resolve_format(int nbr, t_format *format);
char		*itoa(int n);
void		print_string_int(char *string, t_format *format);
int			print_width_int(t_format *format, int digits);
int			print_precision_int(t_format *format, int digits);

// %u

void		print_uninteger(int nbr, t_format *format);
void		resolve_format_unint(unsigned int nbr, t_format *format);
char		*uitoa(unsigned int n);
void		print_string_unint(char *string, t_format *format);
int			print_width_unint(t_format *format, int digits);
int			print_precision_unint(t_format *format, int digits);

// %x & %X

void		print_hexadecimal(unsigned int i, t_format *format);
void		resolve_format_hexa(unsigned int nbr, t_format *format);
char		*itohexa(unsigned	int nbr, t_format *format);
void		print_string_hexa(char *string, t_format *format);
int			print_width_hexa(t_format *format, int digits);
int			print_precision_hexa(t_format *format, int digits);

#endif