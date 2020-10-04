/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	task_checker_part_2(t_array *arr_a, t_array *arr_b, char *line)
{
	if (!ft_strcmp(line, "rb"))
		rorate_arr(arr_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rorate_arr(arr_a);
		rorate_arr(arr_b);
	}
	else if (!ft_strcmp(line, "rra"))
		reverse_rorate_arr(arr_a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rorate_arr(arr_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rorate_arr(arr_a);
		reverse_rorate_arr(arr_b);
	}
	else
	{
		write(2, "Error\n", 6);
		free_arr(arr_a);
		free_arr(arr_b);
		free(line);
		exit(1);
	}
}

void	task_checker(t_array *arr_a, t_array *arr_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa"))
			swap_arr(arr_a);
		else if (!ft_strcmp(line, "sb"))
			swap_arr(arr_b);
		else if (!ft_strcmp(line, "ss"))
		{
			swap_arr(arr_a);
			swap_arr(arr_b);
		}
		else if (!ft_strcmp(line, "pa"))
			push_arr(arr_b, arr_a);
		else if (!ft_strcmp(line, "pb"))
			push_arr(arr_a, arr_b);
		else if (!ft_strcmp(line, "ra"))
			rorate_arr(arr_a);
		else
			task_checker_part_2(arr_a, arr_b, line);
		free(line);
	}
}

void	check_checker(t_array *arr_a, t_array *arr_b)
{
	if ((is_asceding_order(arr_a) == 0) && !(arr_b->data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
		task_checker(arr_a, arr_b);
		check_checker(arr_a, arr_b);
	}
	free_arr(arr_a);
	free_arr(arr_b);
	return (0);
}
