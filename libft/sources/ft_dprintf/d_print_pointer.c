/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:59:57 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_dprintf.h"
#include <stdint.h>

void	d_print_pointer(void *pointer, t_dformat *format)
{
	uintptr_t	ptr_value;
	char		*string;

	ptr_value = (uintptr_t)pointer;
	string = d_itohexa_ptr(ptr_value);
	d_print_string(string, format);
	free(string);
}

char	*d_itohexa_ptr(uintptr_t address)
{
	char	arr[100];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (address == 0)
	{
		arr[i] = '0';
		i++;
	}
	while (address != 0)
	{
		arr[i] = base[address % 16];
		address /= 16;
		i++;
	}
	arr[i++] = 'x';
	arr[i++] = '0';
	return (d_reverse_string(arr, i));
}

char	*d_itohexa(unsigned int nbr, t_dformat *format)
{
	char	arr[100];
	char	*base;
	int		i;

	if (!format->uppercase)
		base = "0123456789abcdef";
	else if (format->uppercase)
		base = "0123456789ABCDEF";
	i = 0;
	if (nbr == 0)
	{
		arr[i] = '0';
		i++;
	}
	while (nbr != 0)
	{
		arr[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	return (d_reverse_string(arr, i));
}

char	*d_reverse_string(char *string, int length)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = length - 1;
	while (i < length / 2)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++;
		j--;
	}
	string[length] = '\0';
	return (ft_strdup(string));
}
