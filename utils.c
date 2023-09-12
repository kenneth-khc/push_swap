/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/12 18:20:47 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_strings(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}

void	validate_instruction(char *instruction,
			t_operation_map (*operation_map)[], int map_size)
{
	int	i;
	int	comparison_len;

	i = 0;
	while (i < map_size)
	{
		comparison_len = ft_strlen(instruction) + 1;
		printf("n: %d\n", comparison_len);
		if (ft_strncmp(instruction, (*operation_map)[i].operation_name,
			comparison_len) == 0)
		{
			return ;
		}
		i++;
	}
	error();
}

void	execute_instructions(t_instruction *list_of_instructions,
		t_operation_map (*map)[], t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	*instruction;

	while (list_of_instructions->next)
	{
		i = 0;
		while (i < 11)
		{
			instruction = list_of_instructions->instruction;
			if (ft_strncmp(instruction, (*map)[i].operation_name,
				ft_strlen(instruction + 1)) == 0)
				(*map)[i].operation(stack_a, stack_b);
			i++;
		}
		free_and_move_list(&list_of_instructions);
	}
}

void	initialize_operation_map(t_operation_map	(*operation_map)[])
{
	(*operation_map)[0] = (t_operation_map){"sa\n", sa};
	(*operation_map)[1] = (t_operation_map){"sb\n", sb};
	(*operation_map)[2] = (t_operation_map){"ss\n", ss};
	(*operation_map)[3] = (t_operation_map){"pa\n", pa};
	(*operation_map)[4] = (t_operation_map){"pb\n", pb};
	(*operation_map)[5] = (t_operation_map){"ra\n", ra};
	(*operation_map)[6] = (t_operation_map){"rb\n", rb};
	(*operation_map)[7] = (t_operation_map){"rr\n", rr};
	(*operation_map)[8] = (t_operation_map){"rra\n", rra};
	(*operation_map)[9] = (t_operation_map){"rrb\n", rrb};
	(*operation_map)[10] = (t_operation_map){"rrr\n", rrr};
}
