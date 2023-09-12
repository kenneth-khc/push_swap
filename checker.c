/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:53 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/12 18:07:33 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				*list_of_integers;
	int				size;
	t_stack			a;
	t_stack			b;
	t_instruction	list_of_instructions;

	size = 0;
	// printf("ARGV[1] = %s\nARGV[2] = %s\n", argv[1], argv[2]);
	list_of_integers = parse_arguments(argc, ++argv, &size);
	init_stacks(list_of_integers, size, &a, &b);
	read_and_exec_instructions(&list_of_instructions, &a, &b);
	if (stack_a_is_sorted(&a) && !stack_b_has_elements(&b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// peek_entire_stack(a, b);
}

void	read_and_exec_instructions(t_instruction *list_of_instructions,
		t_stack *a, t_stack *b)
{
	t_operation_map	operation_map[11];
	int				map_size;
	t_instruction	*current;

	initialize_operation_map(&operation_map);
	map_size = sizeof(operation_map) / sizeof(*operation_map);
	current = list_of_instructions;
	while (1)
	{
		current->instruction = get_next_line(STDIN_FILENO);
		printf("line: %s\n", current->instruction);
		if (current->instruction == NULL)
		{
			current->next = NULL;
			break ;
		}
		validate_instruction(current->instruction, &operation_map, map_size);
		current->next = malloc(sizeof(t_instruction));
		current = current->next;
	}
	execute_instructions(list_of_instructions, &operation_map, a, b);
	// peek_entire_stack(*a, *b);
}

void	execute_instructions1(t_instruction *list_of_instructions,
		t_stack *a, t_stack *b)
{
	while (list_of_instructions->next)
	{
		// printf("EXECUTE: %s\n", list_of_instructions->instruction);
		if (ft_strncmp(list_of_instructions->instruction, "sa\n", 4) == 0)
			sa(a);
		else if (ft_strncmp(list_of_instructions->instruction, "sb\n", 4) == 0)
			sb(b);
		else if (ft_strncmp(list_of_instructions->instruction, "ss\n", 4) == 0)
			ss(a, b);
		else if (ft_strncmp(list_of_instructions->instruction, "pa\n", 4) == 0)
			pa(a, b);
		else if (ft_strncmp(list_of_instructions->instruction, "pb\n", 4) == 0)
			pb(a, b);
		else if (ft_strncmp(list_of_instructions->instruction, "ra\n", 4) == 0)
			ra(a);
		else if (ft_strncmp(list_of_instructions->instruction, "rb\n", 4) == 0)
			rb(b);
		else if (ft_strncmp(list_of_instructions->instruction, "rr\n", 4) == 0)
			rr(a, b);
		else if (ft_strncmp(list_of_instructions->instruction, "rra\n", 5) == 0)
			rra(a);
		else if (ft_strncmp(list_of_instructions->instruction, "rrb\n", 5) == 0)
			rrb(b);
		else if (ft_strncmp(list_of_instructions->instruction, "rrr\n", 5) == 0)
			rrr(a, b);
		free_and_move_list(&list_of_instructions);
	}
}

void	free_and_move_list(t_instruction **node)
{
	free((*node)->instruction);
	*node = (*node)->next;
}

void	validate_instruction1(char	*instruction)
{
	if (ft_strncmp(instruction, "sa\n", 4) == 0
		|| ft_strncmp(instruction, "sb\n", 4) == 0
		|| ft_strncmp(instruction, "ss\n", 4) == 0
		|| ft_strncmp(instruction, "pa\n", 4) == 0
		|| ft_strncmp(instruction, "pb\n", 4) == 0
		|| ft_strncmp(instruction, "ra\n", 4) == 0
		|| ft_strncmp(instruction, "rb\n", 4) == 0
		|| ft_strncmp(instruction, "rr\n", 4) == 0
		|| ft_strncmp(instruction, "rra\n", 5) == 0
		|| ft_strncmp(instruction, "rrb\n", 5) == 0
		|| ft_strncmp(instruction, "rrr\n", 5) == 0)
		return ;
	error();
}

// void	validate_instruction(char *instruction)
// {
// 	if (ft_strncmp(instruction, "sa\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "pa\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "ra\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
// 		return ;
// 	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
// 		return ;
// 	error();
// }