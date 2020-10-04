/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_num_first(t_array *arr, int a)
{
	int				*tmp_data;
	unsigned int	i;

	arr->size++;
	tmp_data = (int*)malloc(sizeof(int) * arr->size);
	i = 0;
	while (i < (arr->size - 1))
	{
		tmp_data[i + 1] = arr->data[i];
		i++;
	}
	tmp_data[0] = a;
	free(arr->data);
	arr->data = tmp_data;
}

void		pop_num_first(t_array *arr)
{
	int				*tmp_data;
	unsigned int	i;

	if (!arr || (arr->size == 0))
		return ;
	arr->size--;
	if (arr->size == 0)
		tmp_data = NULL;
	else
	{
		tmp_data = (int *)malloc(sizeof(int) * arr->size);
		if (!tmp_data)
			exit(1);
		i = 0;
		while (i < arr->size)
		{
			tmp_data[i] = arr->data[i + 1];
			i++;
		}
	}
	free(arr->data);
	arr->data = tmp_data;
}

t_array		*init_arr(char c)
{
	t_array		*tmp_arr;

	tmp_arr = (t_array*)malloc(sizeof(t_array));
	tmp_arr->data = NULL;
	tmp_arr->size = 0;
	tmp_arr->name = c;
	return (tmp_arr);
}

void		free_arr(t_array *arr)
{
	if (arr)
	{
		if (arr->data)
			free(arr->data);
		free(arr);
	}
}

void		add_num_back(t_array *arr, int a)
{
	int				*tmp_data;
	unsigned int	i;

	arr->size++;
	tmp_data = (int*)malloc(sizeof(int) * arr->size);
	if (!tmp_data)
		exit(1);
	i = 0;
	while (i < (arr->size - 1))
	{
		tmp_data[i] = arr->data[i];
		i++;
	}
	tmp_data[i] = a;
	free(arr->data);
	arr->data = tmp_data;
}
