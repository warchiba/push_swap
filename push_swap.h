/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libfunc.h"

typedef struct	s_array
{
	int					*data;
	unsigned int		size;
	char				name;
}				t_array;

t_array			*init_arr(char c);
void			print_arr(const t_array *arr);
void			free_arr(t_array *arr);
void			add_num_back(t_array *arr, int a);
void			add_num_first(t_array *arr, int a);
void			pop_num_first(t_array *arr);
void			swap_arr(t_array *arr);
void			push_arr(t_array *arr_a, t_array *arr_b);
void			rorate_arr(t_array *arr);
void			reverse_rorate_arr(t_array *arr);
double			mediana_arr(t_array *arr);
void			create_arr(t_array *arr, t_array *arr_b, int argc, char **argv);
int				is_asceding_order(t_array *arr);
int				is_desceding_order(t_array *arr);
void			swap_int(int *a, int *b);
void			push_swap_two(t_array *arr);
void			push_swap_three(t_array *arr);
void			print_pa(t_array *arr);
void			push_swap(t_array *arr_a, int lvl_a, int lvl_b);
#endif
