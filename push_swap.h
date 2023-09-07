/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 23:02:25 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack	t_stack;

struct s_stack
{
	int		value;
	t_stack	*next;
};

void	add_integer_to_stack(char *argv, t_stack *head);
int		*split_one_arg(char *arg);
int		*store_args(char **argv);


// Utils
void	error(void);
void	check_list_for_errors(int *list_of_integers, char **argv);
void	is_integer(int integer, char *arg);
int		number_of_strings(char **strings);

#endif