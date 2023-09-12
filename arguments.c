/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:07:13 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/13 01:08:55 by kecheong         ###   ########.fr       */
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
	int	*list_of_integers;

	list_of_integers = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		list_of_integers = store_one_arg(argv, size);
	else if (argc > 2)
		list_of_integers = store_args(argv, size);
	return (list_of_integers);
}

/**
 * Case where integers are passed in only as a single string.
 * E.g. "42 5 2 4"
*/

int	*store_one_arg(char **argv, int *size)
{
	char	**strings;
	char	**original;
	int		*list_of_integers;
	int		*ret;

	strings = ft_split(argv[0], ' ');
	original = strings;
	*size = number_of_strings(strings);
	list_of_integers = malloc(sizeof(int) * *size);
	if (!list_of_integers)
		error();
	ret = list_of_integers;
	while (*strings)
	{
		*list_of_integers++ = ft_atoi(*strings++);
		// printf("STORING: %d\n", *list_of_integers++);
	}
	validate_integers(ret, original);
	return (ret);
}

/**
 * Case where integers are passed in as multiple strings.
 * E.g. 42 5 2 4
*/

int	*store_args(char **argv, int *size)
{
	int		*list_of_integers;
	int		*ret;
	char	**original;

	original = argv;
	*size = number_of_strings(argv);
	list_of_integers = malloc(sizeof(int) * *size);
	if (!list_of_integers)
		error();
	ret = list_of_integers;
	while (*argv)
	{
		*list_of_integers++ = ft_atoi(*argv++);
		// printf("STORING: %d\n", *list_of_integers++);
	}
	validate_integers(ret, original);
	return (ret);
}
