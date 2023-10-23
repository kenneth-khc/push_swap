/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:33:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * Locates the first occurrence of c in string s
 * It expects the string to be null terminated, unlike memchr 
**/

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char) c)
		s++;
	if (*s == (unsigned char) c)
		return ((char *)(s));
	return (NULL);
}
