/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:33:38 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Creates a substring from string "s" 
 * that starts at index "start" and up to "len" 
**/

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	char			*ptr_to_substring;
	size_t			str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (len > str_len)
		len = str_len;
	if (start >= str_len)
		return (ft_strdup(""));
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	ptr_to_substring = substring;
	while (len--)
		*substring++ = *(s + start++);
	*substring = '\0';
	return (ptr_to_substring);
}
