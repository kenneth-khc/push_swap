/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:05:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns a new copy of a string 
 * after trimming the characters in "set" from "s1"
 * Starts trimming from the beginning and the end of the string 
**/

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*new_str;
	size_t		new_str_len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = start + (ft_strlen(s1) - 1);
	while (start <= end && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	new_str_len = end - start + 1;
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, start, new_str_len);
	new_str[new_str_len] = '\0';
	return (new_str);
}
