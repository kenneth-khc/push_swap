/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 01:56:50 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

/* Represents an integer array and its size. */
typedef struct s_int_array
{
	int	*buf;
	int	size;
}	t_arr;

/** 
 * Represents a node in a singly linked list.
 *
 * Members:
 * 		data: the actual number 
 * 		id  : the position the number should be in
 * 		next: pointer to the next node
*/
typedef struct s_node
{
	int				data;
	int				id;
	struct s_node	*next;
}	t_node;

/* Contains the address to top node of the stack. */
typedef struct s_stack
{
	t_node	*top;
}	t_stack;

/* Contains the address to both stacks A and B. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

/** 
 * Represents an unsorted section within a stack.
 * 
 * Members:
 * 		len: the length of the unsorted section
 * 		in: the stack the section currently is in
 * 		prev: pointer to the previous section
 * 		next: pointer to the next section
 * 
 * Each time numbers are pushed to the opposite stack,
 * a section is added. Each time numbers are sorted and
 * they are where they belong, a section is removed.
*/
typedef struct s_section
{
	int					len;
	char				in;
	struct s_section	*prev;
	struct s_section	*next;
}	t_section;

/* Contains pointers to the start and end of the list of sections. */
typedef struct s_sections
{
	t_section	*head;
	t_section	*tail;
}	t_sections;

/* Directions for shifting the stack up or down. */
enum e_directions {
	UP = 'U',
	DOWN = 'D'
};

/* Pointer to sorting functions */
typedef void	(*t_sorter_ptr)(t_stack *, t_stack *);

/* Arguments */
void	parse_arguments(int argc, char **argv, t_arr *integers);
char	*join_arguments(char *s1, const char *s2);
char	**extract_arguments(char **argv, int *size);
void	validate_integers(int *integers, char **argv);
char	*trim_front(char *s1, char const *set);
void	check_for_duplicates(t_arr *array);
void	init_stacks(t_stacks *stacks, t_arr *int_array);
t_arr	*process_numbers(t_arr *int_array);
void	simplify_stack(t_arr *array, t_stack *a);

/* Quicksort */
void	quick_sort(t_arr *array);
void	quick_sort_recurse(int *array, int start_index, int end_index);
int		partition(int *array, int start_index, int end_index);
void	swap(int *x, int *y);

/* Operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Optimized operations */
void	optimized_swap(char stack, t_stack *a, t_stack *b);
void	shift_stack(char direction, char current_stack, t_stack *a, t_stack *b);
bool	rr_optimizable(t_stack *b);
bool	rrr_optimizable(t_stack *b);

/* Sections */
void	add_unsorted_section(char location, int len, t_sections *sections);
void	remove_sorted_a(t_sections *sections);
void	remove_last_section(t_sections *sections);
void	remove_current_section_a(t_sections *sections, t_section *current);
void	clear_sorted_sections(t_sections *sections, t_stacks *stacks);
bool	last_section_in_b(t_section *current);

/* Optimizing first section */
void	check_first_half(t_stacks *stacks, t_sections *sects, int *first_mid);
bool	not_dividable_further(t_section *unsorted_a, t_section *first_half);
void	push_first_section(t_stacks *stacks, int to_push, int mid);
int		find_mid_greater_than_first(t_stack *a, int first_mid);
bool	top_is_first_section(t_stack *a, int first_mid);
int		count_nums_greater_than_first(t_stack *a, int first_mid, int mid);
void	slot_into_first(t_stacks *stacks, int first_mid, int mid, int *pushed);
bool	has_remaining_first(t_stack *a, int first_mid);
void	clear_remaining(t_stacks *stacks, t_sections *sections, int first_mid);
bool	not_only_first_section(t_stack *a, int first_mid);

/* Sorting stack A */
void	sort(t_stacks *stacks, int size);
void	half_a_to_b(t_stacks *stacks, t_sections *sections, int first_mid);
void	sort_a(t_stacks *stacks, t_sections *list);
int		push_to_b(t_stacks *stacks, int first_mid, int mid, int to_push);
void	solve_a(t_stacks *stacks, int len);
void	sort_two(t_stack *a, t_stack *b);
void	sort_three(t_stack *a, t_stack *b);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_section_a(t_stack *a, t_stack *b, int section_len);
int		half_b_to_a(int to_push, int mid, t_stack *a, t_stack *b);
int		count_nums_to_push_b(int mid, t_stack *stack, int section_len);
int		pushback_to_b(int to_push, int mid, t_stack *a, t_stack *b);

/* Sorting stack B */
void	sort_b(t_stacks *stacks, t_sections *list);
void	divide_section(t_stacks *stacks, t_sections *sections);
int		divide_section_b(t_stacks *stacks, t_section *section);
void	div_a_till_sorted(t_stacks *stacks, t_sections *sections, t_section *a);
void	sort_section_b(t_stack *a, t_stack *b, int section_len);
int		divide_section_a(t_stack *a, t_stack *b, t_section *section);
void	sort_while_shifting_down(t_stack *a, t_stack *b, int section_len);
int		fix_shifted_stack(t_stacks *stacks, t_section *section, int shifted_up);

/* Stack utils */
void	push(t_stack *stack, int data);
bool	stacks_are_sorted(t_stack *a, t_stack *b);
bool	elements_are_ascending(t_stack *stack);
bool	section_is_ascending(t_stack *stack, int len);
bool	top_is_descending(t_stack *s);
int		find_section_midpoint(t_stack *stack, int section_len);
bool	section_is_descending(t_stack *stack, int len);
bool	b_top_out_of_place(t_stack *stack);
bool	a_top_out_of_place(t_stack *stack);
bool	has_two_elements(t_stack *stack);
void	free_stacks(t_stacks *stacks);
int		last_node_id(t_stack *stack);
int		count_nums_to_push(t_stack *a, int mid);
void	error(void);
int		find_min(t_stack *a);
void	assign_three_nodes(t_stack *a, t_node **f, t_node **s, t_node **t);
void	push_sorted_section(t_stack *a, t_stack *b, int section_len);

#endif