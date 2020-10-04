/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_asceding_order(t_array *arr)
{
	unsigned int		i;

	i = 1;
	while (i < arr->size)
	{
		if (arr->data[i - 1] > arr->data[i])
			return (i);
		i++;
	}
	return (0);
}

int		is_desceding_order(t_array *arr)
{
	unsigned int		i;

	i = 1;
	while (i < arr->size)
	{
		if (arr->data[i - 1] < arr->data[i])
			return (i);
		i++;
	}
	return (0);
}

void	print_arr(const t_array *arr)
{
	unsigned int	i;

	i = 0;
	ft_printf("Size: %u\n", arr->size);
	while (i < arr->size)
	{
		ft_printf("%d ", arr->data[i]);
		i++;
	}
	ft_printf("\n");
}
