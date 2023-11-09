/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/09 20:08:36 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the argument strings and convert them into integers.
 * Calculate the number of integers.
 * Store them sequentially in an array.
 * Check the list to validate the integers, error if non integer found.
*/
t_int_array	*parse_arguments(int argc, char **argv)
{
	char		**strings;
	int			*integers;
	int			i;
	int			size;
	t_int_array	*integs;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	strings = extract_arguments(argv);
	size = count_numbers(strings);
	integers = malloc(sizeof(*integers) * size);
	if (!integers)
		error();
	while (strings[i])
	{
		integers[i] = ft_atoi(strings[i]);
		i++;
	}
	validate_integers(integers, strings);
	integs = malloc(sizeof(t_int_array));
	integs->contents = integers;
	integs->size = size;
	return (integs);
}

/**
 * Extract argv into a single string before splitting it.
 * This allows us to handle cases such as 
 * <./push_swap "5 3 7" 8 2 1> 
 * where certain numbers are quoted and the others are not.
 */
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

/**
 * Join an argument with another.
 * A space is added to the back for delimiting the arguments.
 */
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
	free(s1);
	while (*s2)
		*s3_ptr++ = *s2++;
	*s3_ptr++ = ' ';
	*s3_ptr = '\0';
	return (s3);
}
