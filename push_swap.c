/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	push_swap_two(t_array *arr)
{
	if (((arr->data[0] > arr->data[1]) && (arr->name == 'a')) ||
		((arr->data[0] < arr->data[1]) && (arr->name == 'b')))
	{
		swap_int(&(arr->data[0]), &(arr->data[1]));
		ft_printf("s%c\n", arr->name);
	}
}

void	push_swap_three_part2(t_array *arr)
{
	if ((arr->data[1] > arr->data[2]) && (arr->data[2] > arr->data[0]))
	{
		ft_printf("sa\nra\n");
		swap_arr(arr);
		rorate_arr(arr);
	}
	else if ((arr->data[1] > arr->data[0]) && (arr->data[0] > arr->data[2]))
	{
		ft_printf("rra\n");
		reverse_rorate_arr(arr);
	}
}

void	push_swap_three(t_array *arr)
{
	if ((arr->data[0] > arr->data[1]) && (arr->data[1] > arr->data[2]))
	{
		ft_printf("sa\nrra\n");
		swap_arr(arr);
		reverse_rorate_arr(arr);
	}
	else if ((arr->data[2] > arr->data[0]) && (arr->data[0] > arr->data[1]))
	{
		ft_printf("sa\n");
		swap_arr(arr);
	}
	else if ((arr->data[0] > arr->data[2]) && (arr->data[2] > arr->data[1]))
	{
		ft_printf("ra\n");
		rorate_arr(arr);
	}
	else
		push_swap_three_part2(arr);
}

void	print_pa(t_array *arr)
{
	unsigned int i;

	i = 0;
	while (i < arr->size)
	{
		ft_printf("pa\n");
		i++;
	}
}
