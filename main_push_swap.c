/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	division_part_2(t_array *arr_a, int lvl_a, int lvl_b, int count)
{
	if (((arr_a->name == 'a') && (lvl_a > 0)) ||
		((arr_a->name == 'b') && (lvl_b > 0)))
		while (count > 0)
		{
			ft_printf("rr%c\n", arr_a->name);
			reverse_rorate_arr(arr_a);
			count--;
		}
}

void	division_part(t_array *arr_a, t_array *arr_b,
		int lvl_a, int lvl_b)
{
	int				count;
	unsigned int	size;
	double			med;

	size = arr_a->size;
	med = mediana_arr(arr_a);
	count = 0;
	while (1)
	{
		if ((((double)arr_a->data[0] < med) && (arr_a->name == 'a')) ||
			(((double)arr_a->data[0] > med) && (arr_a->name == 'b')))
		{
			ft_printf("p%c\n", arr_b->name);
			push_arr(arr_a, arr_b);
		}
		else
		{
			ft_printf("r%c\n", arr_a->name);
			rorate_arr(arr_a);
			count++;
		}
		if (arr_b->size == (size / 2))
			break ;
	}
	division_part_2(arr_a, lvl_a, lvl_b, count);
}

void	recurtion(t_array *arr_a, t_array *arr_b,
		int lvl_a, int lvl_b)
{
	if (arr_a->name == 'a')
	{
		push_swap(arr_a, lvl_a, lvl_b + 1);
		push_swap(arr_b, lvl_a + 1, lvl_b + 1);
	}
	else
	{
		push_swap(arr_b, lvl_a + 1, lvl_b + 1);
		push_swap(arr_a, lvl_a, lvl_b + 1);
	}
}

void	push_swap(t_array *arr_a, int lvl_a, int lvl_b)
{
	t_array		*arr_b;
	char		c;

	if ((arr_a->size == 3) && (arr_a->name == 'a') && (lvl_a == 0))
		push_swap_three(arr_a);
	if ((is_asceding_order(arr_a) == 0) && (arr_a->name == 'a'))
		return ;
	if ((is_desceding_order(arr_a) == 0) && (arr_a->name == 'b'))
	{
		print_pa(arr_a);
		return ;
	}
	if (arr_a->size == 2)
	{
		push_swap_two(arr_a);
		if (arr_a->name == 'b')
			print_pa(arr_a);
		return ;
	}
	c = (arr_a->name == 'a') ? 'b' : 'a';
	arr_b = init_arr(c);
	division_part(arr_a, arr_b, lvl_a, lvl_b);
	recurtion(arr_a, arr_b, lvl_a, lvl_b);
	free_arr(arr_b);
}

int		main(int argc, char **argv)
{
	t_array			*arr_a;
	t_array			*arr_b;

	arr_a = init_arr('a');
	arr_b = init_arr('b');
	if (argc > 1)
	{
		create_arr(arr_a, arr_b, argc, argv);
		if (arr_a->size == 2)
			push_swap_two(arr_a);
		else if (arr_a->size == 3)
			push_swap_three(arr_a);
		else
			push_swap(arr_a, 0, -1);
	}
	free_arr(arr_b);
	free_arr(arr_a);
	return (0);
}
