/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 19:03:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the argument strings and convert them into integers.
 * Calculate the number of integers.
 * Store them sequentially in an array.
 * Check the list to validate the integers, error if non integer found.
*/
int	*parse_arguments(int argc, char **argv, int *size)
{
	char	**strings;
	int		*integer_arr;
	int		i;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	strings = extract_arguments(argv);
	*size = count_numbers(strings);
	integer_arr = malloc(sizeof(*size) * *size);
	if (!integer_arr)
		error();
	while (strings[i])
	{
		integer_arr[i] = ft_atoi(strings[i]);
		i++;
	}
	validate_integers(integer_arr, strings);
	return (integer_arr);
}

char	**extract_arguments(char **argv)
{
	char	*joined_args;
	char	**strings;

	joined_args = malloc(1);
	*joined_args = '\0';
	while (*argv)
	{
		joined_args = join_arguments(joined_args, *argv);
		argv++;
	}
	strings = ft_split(joined_args, ' ');
	free(joined_args);
	return (strings);
}

char	*join_arguments(char *s1, const char *s2)
{
	char	*s1_ptr;
	char	*s3;
	char	*s3_ptr;

	if (*s2 == '\0')
		error();
	s1_ptr = s1;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(*s1));
	if (!s3)
		error();
	s3_ptr = s3;
	while (*s1_ptr)
		*s3_ptr++ = *s1_ptr++;
	while (*s2)
		*s3_ptr++ = *s2++;
	*s3_ptr++ = ' ';
	*s3_ptr = '\0';
	free(s1);
	return (s3);
}
