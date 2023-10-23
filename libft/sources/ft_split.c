/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:30:19 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Splits a string into substrings based on a delimiter
 * Returns an array of substrings
 * Array ends with a NULL pointer

 * Count the number of words in the string by determining if
 * the current character is a delimiter or not
 * Step through the string and increment the word count
 * Malloc with the word count + 1 to account for the NULL pointer

 * Iterate through the substring to get its length
 * Use length in ft_substr to get the substring 
**/

#include "../includes/libft.h"

static int	count_words(char const *string, char delimiter)
{
	int		word_count;
	bool	in_word;

	word_count = 0;
	in_word = false;
	while (*string)
	{
		if (*string++ == delimiter)
			in_word = false;
		else if (in_word == false)
		{
			word_count++;
			in_word = true;
		}
	}
	return (word_count);
}

static char	*store_substring(char const *string, size_t len)
{
	char	*substring;

	if (!len)
		return (NULL);
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	*(substring + len) = '\0';
	while (len--)
		*(substring + len) = *(string + len);
	return (substring);
}

char	**ft_split(char const *string, char delimiter)
{
	int		word_count;
	char	**strings;
	int		i;
	size_t	len;

	if (!string)
		return (NULL);
	word_count = count_words(string, delimiter);
	strings = malloc((word_count + 1) * sizeof (*strings));
	if (!strings)
		return (NULL);
	i = 0;
	while (*string)
	{
		while (*string == delimiter)
			string++;
		len = 0;
		while (*(string + len) && *(string + len) != delimiter)
			len++;
		*(strings + i++) = store_substring(string, len);
		string += len;
	}
	*(strings + word_count) = NULL;
	return (strings);
}
