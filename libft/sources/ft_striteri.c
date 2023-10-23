/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:24:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies the function f to each character of the string passed
**/

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return ;
	while (*(s + ++i))
		f(i, s + i);
}

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char s[] = "0000000000";
// 	ft_striteri(s, iter);
// 	printf("%s\n", s);
// }