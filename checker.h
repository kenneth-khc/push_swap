/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:21:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 18:00:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/includes/libft.h"
# include "push_swap.h"
# include <stdio.h>
# include <stdbool.h>

# define NUM_OF_INSTRUCTIONS 11

typedef struct s_instruction		t_instruction;
typedef void						(*t_function_pointer)();
typedef struct s_instruction_table	t_instruction_table;

struct s_instruction
{
	char			*instruction;
	t_instruction	*next;
};

struct s_instruction_table
{
	const char			*instruction_name;
	t_function_pointer	instruction;
};

// Checker
void	read_and_exec_instructions(t_instruction *list_of_instructions,
			t_stack *a, t_stack *b);
void	init_instruction_table(t_instruction_table(*instruction_table)[]);
void	validate_instruction(char *instruction,
			t_instruction_table (*instruction_table)[]);
void	execute_instructions(t_instruction *list_of_instructions,
			t_instruction_table (*instruction_table)[], t_stack *a, t_stack *b);

// Utils
void	free_and_move_list(t_instruction **node);
bool	stack_has_elements(t_stack *stack);

#endif