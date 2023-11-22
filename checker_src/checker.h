/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:21:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 23:52:56 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../push_swap.h"

enum e_instructions {
	NUM_OF_INSTRUCTIONS = 11
};

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

/* Checker operations */
void	checker_sa(t_stack *a, t_stack *b);
void	checker_sb(t_stack *a, t_stack *b);
void	checker_ss(t_stack *a, t_stack *b);
void	checker_pa(t_stack *a, t_stack *b);
void	checker_pb(t_stack *a, t_stack *b);
void	checker_ra(t_stack *a, t_stack *b);
void	checker_rb(t_stack *a, t_stack *b);
void	checker_rr(t_stack *a, t_stack *b);
void	checker_rra(t_stack *a, t_stack *b);
void	checker_rrb(t_stack *a, t_stack *b);
void	checker_rrr(t_stack *a, t_stack *b);

/* Checker */
void	read_and_exec_instructions(t_stack *a, t_stack *b);
void	init_instruction_table(t_instruction_table(*instruction_table)[]);
void	validate_instruction(char *instruction,
			t_instruction_table (*instruction_table)[]);
void	execute_instructions(t_instruction *instructions_list,
			t_instruction_table (*instruction_table)[], t_stack *a, t_stack *b);

/* Utils */
bool	stack_is_empty(t_stack *stack);
void	free_instruction_list(t_instruction *head);

#endif