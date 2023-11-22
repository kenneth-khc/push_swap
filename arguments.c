/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:50 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 01:37:23 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the argument strings and convert them into integers.
 * Calculate the number of integers.
 * Store them sequentially in an array.
 * Check the list to validate the integers, error if non integer found.
*/
void	parse_arguments(int argc, char **argv, t_arr *integers)
{
	int			i;
	int			size;
	int			*buf;
	char		**strings;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	strings = extract_arguments(argv, &size);
	buf = malloc(sizeof(*buf) * size);
	if (NULL == buf)
		error();
	i = 0;
	while (strings[i])
	{
		buf[i] = ft_atoi(strings[i]);
		i++;
	}
	validate_integers(buf, strings);
	integers->buf = buf;
	integers->size = size;
}

/**
 * Extract argv into a single string before splitting it.
 * This handles cases such as
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

/**
 * Using the list of integers stored in the array,
 * convert each element back to a string and
 * compare it with the original string.
 * If they do not match, a non integer was entered, therefore error.
 * + signs are trimmed.
*/
void	validate_integers(int *integers, char **strings)
{
	int		i;
	int		len;
	char	*trimmed_arg;
	char	*reconverted;

	i = 0;
	while (strings[i])
	{
		trimmed_arg = trim_front(strings[i], "+");
		reconverted = ft_itoa(integers[i]);
		len = ft_strlen(reconverted) + 1;
		if (ft_strncmp(reconverted, trimmed_arg, len))
			error();
		free(reconverted);
		free(trimmed_arg);
		free(strings[i]);
		i++;
	}
	free(strings);
}

char	*trim_front(char *s1, char const *set)
{
	int		i;
	char	*start;
	char	*trimmed;

	if (NULL == s1 || NULL == set)
		return (NULL);
	start = s1;
	while (start && *start && ft_strchr(set, *start))
		start++;
	trimmed = malloc(sizeof(*trimmed) * (ft_strlen(start) + 1));
	if (NULL == trimmed)
		return (NULL);
	i = 0;
	while (start[i])
	{
		trimmed[i] = start[i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
