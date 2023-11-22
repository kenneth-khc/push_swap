/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 01:21:10 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * This is a program to check if given a list of operations on a stack of
 * integers, whether the list of operations 
 * successfully sorts the stack or not.
 */
int	main(int argc, char **argv)
{
	t_stacks		stacks;
	t_arr			int_array;

	parse_arguments(argc, ++argv, &int_array);
	init_stacks(&stacks, &int_array);
	read_and_exec_instructions(stacks.a, stacks.b);
	if (stacks_are_sorted(stacks.a, stacks.b))
		ft_printf("OK\n");
	else
		ft_dprintf(STDERR_FILENO, "KO\n");
	free_stacks(&stacks);
}

/**
 * Once the arguments passed into the program are formatted as a stack 
 * of integers, read the input for instructions to be performed on the stack.
 * The instructions read are stored in a singly linked list, with CTRL-D
 * signalling the end of the instructions.
 * After storing all instructions, operate on the stack.
 */
void	read_and_exec_instructions(t_stack *a, t_stack *b)
{
	t_instruction		*start;
	t_instruction		*current;
	t_instruction_table	instruction_table[NUM_OF_INSTRUCTIONS];

	init_instruction_table(&instruction_table);
	start = malloc(sizeof(*start));
	current = start;
	while (current)
	{
		current->instruction = get_next_line(STDIN_FILENO);
		if (NULL == current->instruction)
		{
			current->next = NULL;
			break ;
		}
		validate_instruction(current->instruction, &instruction_table);
		current->next = malloc(sizeof(*current));
		current = current->next;
	}
	execute_instructions(start, &instruction_table, a, b);
	free_instruction_list(start);
}

/**
 * Initialize an array of structs containing strings of the name of
 * the operations and a pointer to its function.
 * This array of structures will be known as the instruction table.
 */
void	init_instruction_table(t_instruction_table (*table)[])
{
	(*table)[0] = (t_instruction_table){"sa\n", checker_sa};
	(*table)[1] = (t_instruction_table){"sb\n", checker_sb};
	(*table)[2] = (t_instruction_table){"ss\n", checker_ss};
	(*table)[3] = (t_instruction_table){"pa\n", checker_pa};
	(*table)[4] = (t_instruction_table){"pb\n", checker_pb};
	(*table)[5] = (t_instruction_table){"ra\n", checker_ra};
	(*table)[6] = (t_instruction_table){"rb\n", checker_rb};
	(*table)[7] = (t_instruction_table){"rr\n", checker_rr};
	(*table)[8] = (t_instruction_table){"rra\n", checker_rra};
	(*table)[9] = (t_instruction_table){"rrb\n", checker_rrb};
	(*table)[10] = (t_instruction_table){"rrr\n", checker_rrr};
}

/**
 * Validate the instruction read by the program.
 * If it does not match any of the possible instructions,
 * immediately throw an error.
 */
void	validate_instruction(char *instruction,
			t_instruction_table (*table)[])
{
	int			i;
	int			len;
	const char	*name;

	i = 0;
	while (i < NUM_OF_INSTRUCTIONS)
	{
		len = ft_strlen(instruction) + 1;
		name = (*table)[i].instruction_name;
		if (!ft_strncmp(instruction, name, len))
			return ;
		i++;
	}
	error();
}

/**
 * Iterate through the list of instructions and execute them in order.
 * Compare the instruction stored with the instruction name listed in
 * the instruction table and call its function accordingly.
 * Free each instruction as it is not longer needed.
*/
void	execute_instructions(t_instruction *instructions_list,
		t_instruction_table (*table)[], t_stack *stack_a, t_stack *stack_b)
{
	int				i;
	int				len;
	const char		*name;
	t_instruction	*current;

	current = instructions_list;
	while (current->next)
	{
		i = 0;
		while (i < NUM_OF_INSTRUCTIONS)
		{
			name = (*table)[i].instruction_name;
			len = ft_strlen(current->instruction) + 1;
			if (!ft_strncmp(current->instruction, name, len))
				(*table)[i].instruction(stack_a, stack_b);
			i++;
		}
		free(current->instruction);
		current = current->next;
	}
}
