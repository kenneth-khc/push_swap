/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:02:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * Duplicates a string by copying it to a newly allocated string
**/

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		strlen;
	char	*s2;
	char	*ptr_to_s2;

	strlen = ft_strlen(s1);
	s2 = malloc((sizeof(char)) * (strlen + 1));
	if (!s2)
		return (NULL);
	ptr_to_s2 = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (ptr_to_s2);
}
