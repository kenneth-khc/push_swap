/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:58:11 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Bzero writes n zeroed bytes to the string s
 * If n is zero, bzero does nothing 
**/

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = 0;
}
