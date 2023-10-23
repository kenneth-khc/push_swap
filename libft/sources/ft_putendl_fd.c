/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:53:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 13:05:59 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Writes a string to a file descriptor and then a newline
**/

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write (fd, s++, 1);
	write(fd, "\n", 1);
}
