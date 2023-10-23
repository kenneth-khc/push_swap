/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:20:55 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies the function f to each character in s
 * Index of the character is the first argument to f 
**/

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			strlen;

	if (!s || !f)
		return (NULL);
	i = 0;
	strlen = ft_strlen(s);
	str = malloc((strlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

// #include <stdio.h>
// char	add_one(unsigned int i, char c)
// {
// 	return (i + c);
// }

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("1234", add_one));
// }
