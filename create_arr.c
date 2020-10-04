/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_str(char *str)
{
	unsigned int	i;

	i = 0;
	if ((str[0] == '-') || (str[0] == '+'))
	{
		if (!str[1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_copy_in_arr(t_array *arr, int n)
{
	unsigned int	i;

	i = 0;
	while (i < arr->size)
	{
		if (arr->data[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int		check_arg(char *str, t_array *arr)
{
	int				num;
	long long int	num_long;

	num_long = ft_atoi(str);
	num = num_long;
	if ((!check_str(str)) || (num != num_long) ||
		!is_copy_in_arr(arr, num))
		return (1);
	return (0);
}

void	finish_arr(t_array *arr, t_array *arr_b)
{
	write(2, "Error\n", 6);
	free_arr(arr);
	free_arr(arr_b);
	exit(1);
}

void	create_arr(t_array *arr, t_array *arr_b,
		int argc, char **argv)
{
	int				i;
	int				size;

	size = 0;
	i = 1;
	if (argc == 2)
	{
		argv = ft_strsplit(argv[1], ' ');
		while (argv[size])
			size++;
		i = 0;
	}
	else
		size = argc;
	while (i < size)
	{
		if (check_arg(argv[i], arr))
			finish_arr(arr, arr_b);
		add_num_back(arr, ft_atoi(argv[i]));
		i++;
	}
}
