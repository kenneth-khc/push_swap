/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/08 23:41:48 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct s_stack
{
	t_node	*top;
};

struct s_node
{
	int		data;
	t_node	*next;
};

void	initialize_stack(int *list_of_integers, int size, t_stack *a, t_stack *b);
int		*parse_arguments(int argc, char **argv, int *size);
int		*store_one_arg(char **argv, int *size);
int		*store_args(char **argv, int *size);


// Utils
void	push(t_stack *stack, int data);
void	error(void);
void	check_integers(int *list_of_integers, char **argv);
void	is_integer(int integer, char *arg);
int		number_of_strings(char **strings);

#endif