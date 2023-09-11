/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:49:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/11 14:41:51 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int *array, int start_index, int end_index)
{
	int	pivot;
	int	middle_index;
	int	i;
	int	j;

	middle_index = start_index + (end_index - start_index) / 2;
	swap(&array[middle_index], &array[end_index]);
	pivot = array[end_index];
	i = start_index - 1;
	j = start_index;
	while (j < end_index)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[j], &array[i]);
		}
		j++;
	}
	i++;
	swap(&array[i], &array[end_index]);
	return (i);
}

void	quick_sort_recurse(int *array, int start_index, int end_index)
{
	int	pivot_index;

	if (start_index >= end_index)
		return ;
	pivot_index = partition(array, start_index, end_index);
	quick_sort_recurse(array, 0, pivot_index - 1);
	quick_sort_recurse(array, pivot_index + 1, end_index);
}

void	quick_sort(int *array, int size)
{
	int	start_index;
	int	end_index;

	start_index = 0;
	end_index = size - 1;
	quick_sort_recurse(array, start_index, end_index);
}