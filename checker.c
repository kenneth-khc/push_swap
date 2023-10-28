/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/26 13:36:58 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This is a program to check if given a list of operations on a stack of
 * integers, whether the list of operations 
 * successfully sorts the stack or not.
 */

int	main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	int				size;
	int				*list_of_integers;
	t_instruction	list_of_instructions;

	size = 0;
	list_of_integers = parse_arguments(argc, ++argv, &size);
	init_stacks(list_of_integers, size, &a, &b);
	read_and_exec_instructions(&list_of_instructions, &a, &b);
	if (elements_are_ascending(&a) && !stack_has_elements(&b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/**
 * Once the arguments passed into the program are formatted as a stack 
 * of integers, read the input for instructions to be performed on the stack.
 * The instructions read are stored in a singly linked list, with CTRL-D
 * signalling the end of the instructions.
 * After storing all instructions, operate on the stack.
 */

void	read_and_exec_instructions(t_instruction *list_of_instructions,
		t_stack *a, t_stack *b)
{
	t_instruction_table	instruction_table[NUM_OF_INSTRUCTIONS];
	t_instruction		*current;

	init_instruction_table(&instruction_table);
	current = list_of_instructions;
	while (1)
	{
		current->instruction = get_next_line(STDIN_FILENO);
		if (current->instruction == NULL)
		{
			current->next = NULL;
			break ;
		}
		validate_instruction(current->instruction, &instruction_table);
		current->next = malloc(sizeof(t_instruction));
		current = current->next;
	}
	execute_instructions(list_of_instructions, &instruction_table, a, b);
}

/**
 * Initialize an array of structures containing strings of the name of
 * the operations and a pointer to its function.
 * This array of structures will be known as the instruction table.
 */

void	init_instruction_table(t_instruction_table (*table)[])
{
	(*table)[0] = (t_instruction_table){"sa\n", sa};
	(*table)[1] = (t_instruction_table){"sb\n", sb};
	(*table)[2] = (t_instruction_table){"ss\n", ss};
	(*table)[3] = (t_instruction_table){"pa\n", pa};
	(*table)[4] = (t_instruction_table){"pb\n", pb};
	(*table)[5] = (t_instruction_table){"ra\n", ra};
	(*table)[6] = (t_instruction_table){"rb\n", rb};
	(*table)[7] = (t_instruction_table){"rr\n", rr};
	(*table)[8] = (t_instruction_table){"rra\n", rra};
	(*table)[9] = (t_instruction_table){"rrb\n", rrb};
	(*table)[10] = (t_instruction_table){"rrr\n", rrr};
}

/**
 * Validate the instruction read by the program.
 * If it does not match any of the possible instructions,
 * immediately throw an error.
 */

void	validate_instruction(char *instruction,
			t_instruction_table (*table)[])
{
	int	i;

	i = 0;
	while (i < NUM_OF_INSTRUCTIONS)
	{
		if (ft_strncmp(instruction, (*table)[i].instruction_name,
			ft_strlen(instruction) + 1) == 0)
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

void	execute_instructions(t_instruction *list_of_instructions,
		t_instruction_table (*table)[], t_stack *stack_a, t_stack *stack_b)
{
	int				i;
	t_instruction	*current;

	current = list_of_instructions;
	while (current->next)
	{
		i = 0;
		while (i < NUM_OF_INSTRUCTIONS)
		{
			if (ft_strncmp(current->instruction, (*table)[i].instruction_name,
				ft_strlen(current->instruction) + 1) == 0)
				(*table)[i].instruction(stack_a, stack_b);
			i++;
		}
		free(current->instruction);
		current = current->next;
	}
}
