/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:29 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * Copies a string from src to dest
**/

#include "../includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_ptr);
}
