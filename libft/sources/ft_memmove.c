/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:25:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Works like memcpy, but it accounts for overlapping memory blocks
 * If dst is greater than src, it means they might overlap
 * Therefore, start copying from the end to not overwrite data
 * that has not been copied yet 
**/

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	i = -1;
	if (dst > src)
		while (len--)
			dst_ptr[len] = src_ptr[len];
	else if (src > dst)
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	return (dst);
}
