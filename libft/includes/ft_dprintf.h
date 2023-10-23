/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:19:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:40:54 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "../includes/libft.h"
# include <stdarg.h>

typedef struct s_dformat
{
	int		fd;

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

}	t_dformat;

// printf.c

int			ft_dprintf(int fd, const char *format, ...);
t_dformat	*d_initialize_struct(void);
void		d_reset_format(t_dformat *format);
int			d_parse_string(char *string, va_list ap, int fd);
int			d_check_format(char *string, int i, t_dformat *format, va_list ap);
int			d_check_type(char *string, int i, t_dformat *format, va_list ap);
int			d_check_precision(char *string, int i, t_dformat *format);
int			d_check_width(char *string, int i, t_dformat *format);
int			d_check_flags(char *string, int i, t_dformat *format);
bool		d_isflag(char c);
bool		d_iswidth(char c);
bool		d_isprecision(char c);
bool		d_istype(char c);
void		d_ft_putstr(char *s);
void		d_ft_putchar(char c);

// %c

void		d_print_char(int c, t_dformat *format);

// %s

void		d_print_string(char *string, t_dformat *format);
void		d_print_width(char *string, t_dformat *format, int str_len, int i);
int			d_print_precision(char *string, t_dformat *format,
				int str_len, int i);

// %p

void		d_print_pointer(void *pointer, t_dformat *format);
char		*d_itohexa_ptr(uintptr_t address);
char		*d_reverse_string(char *string, int length);

// %d & %i

void		d_print_integer(int nbr, t_dformat *format);
void		d_resolve_format(int nbr, t_dformat *format);
char		*d_itoa(int n);
void		d_print_string_int(char *string, t_dformat *format);
int			d_print_width_int(t_dformat *format, int digits);
int			d_print_precision_int(t_dformat *format, int digits);

// %u

void		d_print_uninteger(int nbr, t_dformat *format);
void		d_resolve_format_unint(unsigned int nbr, t_dformat *format);
char		*d_uitoa(unsigned int n);
void		d_print_string_unint(char *string, t_dformat *format);
int			d_print_width_unint(t_dformat *format, int digits);
int			d_print_precision_unint(t_dformat *format, int digits);

// %x & %X

void		d_print_hexadecimal(unsigned int i, t_dformat *format);
void		d_resolve_format_hexa(unsigned int nbr, t_dformat *format);
char		*d_itohexa(unsigned	int nbr, t_dformat *format);
void		d_print_string_hexa(char *string, t_dformat *format);
int			d_print_width_hexa(t_dformat *format, int digits);
int			d_print_precision_hexa(t_dformat *format, int digits);

#endif