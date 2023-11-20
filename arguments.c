/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/20 22:17:13 by kecheong         ###   ########.fr       */
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
	int			i;
	char		**strings;
	int			size;
	int			*buf;
	t_int_array	*integers;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	strings = extract_arguments(argv, &size);
	buf = malloc(sizeof(*buf) * size);
	if (NULL == buf)
		error();
	while (strings[i])
	{
		buf[i] = ft_atoi(strings[i]);
		i++;
	}
	validate_integers(buf, strings);
	integers = malloc(sizeof(t_int_array));
	integers->buf = buf;
	integers->size = size;
	return (integers);
}

/**
 * Extract argv into a single string before splitting it.
 * This allows us to handle cases such as 
 * <./push_swap "5 3 7" 8 2 1> 
 * where certain numbers are quoted and the others are not.
 * Count the number of strings split for the numbers to store.
 */
char	**extract_arguments(char **argv, int *size)
{
	int		i;
	char	**strings;
	char	*joined_args;

	joined_args = malloc(1);
	joined_args[0] = '\0';
	while (*argv)
	{
		joined_args = join_arguments(joined_args, *argv);
		argv++;
	}
	strings = ft_split(joined_args, ' ');
	free(joined_args);
	i = 0;
	while (strings[i])
		i++;
	*size = i;
	return (strings);
}

/**
 * Join an argument with another.
 * A space is added to the back for delimiting the arguments.
 */
char	*join_arguments(char *s1, const char *s2)
{
	int		i;
	char	*s3;

	if (s2[0] == '\0')
		error();
	i = 0;
	s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (NULL == s3)
		error();
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3[i] = ' ';
	s3[++i] = '\0';
	return (s3);
}
