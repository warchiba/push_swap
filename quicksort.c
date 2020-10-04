/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(int **arr, int low, int high)
{
	int		sup;
	int		i;
	int		j;
	int		tmp;

	sup = (*arr)[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while ((*arr)[i] < sup)
			i++;
		while ((*arr)[j] > sup)
			j--;
		if (i >= j)
			break ;
		tmp = (*arr)[i];
		(*arr)[i] = (*arr)[j];
		(*arr)[j] = tmp;
		i++;
		j--;
	}
	return (j);
}

void	quicksort(int **arr, int low, int high)
{
	int		p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quicksort(arr, low, p);
		quicksort(arr, p + 1, high);
	}
}

double	mediana_arr(t_array *arr)
{
	unsigned int		i;
	int					*tmp_arr;
	double				mediana;

	if (arr->size == 1)
		return (arr->data[0]);
	tmp_arr = (int*)malloc(sizeof(int) * arr->size);
	if (!tmp_arr)
		exit(1);
	i = 0;
	while (i < arr->size)
	{
		tmp_arr[i] = arr->data[i];
		i++;
	}
	quicksort(&tmp_arr, 0, arr->size - 1);
	if (arr->size % 2 != 0)
		mediana = tmp_arr[arr->size / 2];
	else
		mediana = (double)(tmp_arr[arr->size / 2] +
				tmp_arr[arr->size / 2 - 1]) / 2;
	free(tmp_arr);
	return (mediana);
}
