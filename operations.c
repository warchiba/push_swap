/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arr(t_array *arr)
{
	int		tmp;

	if (!arr || (arr->size < 2))
		return ;
	tmp = arr->data[0];
	arr->data[0] = arr->data[1];
	arr->data[1] = tmp;
}

void	push_arr(t_array *arr_a, t_array *arr_b)
{
	if (!arr_a || (arr_a->size == 0))
		return ;
	add_num_first(arr_b, arr_a->data[0]);
	pop_num_first(arr_a);
}

void	rorate_arr(t_array *arr)
{
	int				tmp_int;
	unsigned int	i;

	i = 0;
	if (!arr || (arr->size == 0))
		return ;
	tmp_int = arr->data[0];
	while (i < (arr->size - 1))
	{
		arr->data[i] = arr->data[i + 1];
		i++;
	}
	arr->data[i] = tmp_int;
}

void	reverse_rorate_arr(t_array *arr)
{
	int				tmp_int;
	unsigned int	i;

	if (!arr || (arr->size == 0))
		return ;
	i = arr->size - 1;
	tmp_int = arr->data[arr->size - 1];
	while (i > 0)
	{
		arr->data[i] = arr->data[i - 1];
		i--;
	}
	arr->data[0] = tmp_int;
}
