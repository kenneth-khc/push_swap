/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 23:09:32 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head;
	int		*list_of_integers;

	head = NULL;
	list_of_integers = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		list_of_integers = split_one_arg(*++argv);
	else if (argc > 2)
		list_of_integers = store_args(argv);
	check_list_for_errors(list_of_integers, ++argv);
	while (*++argv)
	{
		add_integer_to_stack(*argv, head);
		return(0);
	}
}

int	*split_one_arg(char *arg)
{
	char	**strings;
	int		*list_of_integers;
	int		*ret;

	strings = ft_split(arg, ' ');
	list_of_integers = malloc(sizeof(int) * number_of_strings(strings));
	if (!list_of_integers)
		error();
	ret = list_of_integers;
	while (*strings)
	{
		*list_of_integers = ft_atoi(*strings++);
		printf("%d\n", *list_of_integers++);
	}
	return (ret);
}

int	*store_args(char **argv)
{
	int	*list_of_integers;
	int	*ret;

	list_of_integers = malloc(sizeof(int) * number_of_strings(argv));
	if (!list_of_integers)
		error();
	ret = list_of_integers;
	while (*++argv)
	{
		*list_of_integers = ft_atoi(*argv);
		printf("STORING: %d\n", *list_of_integers++);
	}
	return (ret);
}

void	add_integer_to_stack(char *arg, t_stack *head)
{
	int	integer;

	integer = ft_atoi((char *)arg);
	printf("INT: %d\n", integer);
	if (head == NULL)
		;
}

int	number_of_strings(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}
