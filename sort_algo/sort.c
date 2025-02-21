/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:04:21 by okaname           #+#    #+#             */
/*   Updated: 2025/02/19 13:51:09 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	ft_check_sorted(t_stack *list, int len)
{
	int		num;
	t_stack	*tmp;
	int		i;

	i = 0;
	num = list->number;
	tmp = list->next;
	while (i < len - 1)
	{
		if (num > (tmp->number))
			return (0);
		num = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static void	ft_three_sort(t_data_list *data)
{
	if (ft_check_sorted(data->list_a, data->a_qty))
		return ;
	if (data->list_a->number < data->list_a->next->number
		&& data->list_a->number < data->list_a->prev->number)
	{
		ft_swap_a(data);
		ft_rotate_a(data);
	}
	else if (data->list_a->number < data->list_a->next->number)
		ft_r_rotate_a(data);
	else if (data->list_a->number < data->list_a->prev->number)
		ft_swap_a(data);
	else
	{
		ft_rotate_a(data);
		if (data->list_a->number > data->list_a->next->number)
			ft_swap_a(data);
	}
}

void	ft_lis_rotate(t_data_list *data)
{
	int	i;
	int	j;
	int	flag;
	int	qty;

	i = 0;
	qty = data->a_qty;
	while (i < qty)
	{
		j = 0;
		flag = 0;
		while (j < qty)
		{
			if (data->lis[j] == data->list_a->number)
				flag = 1;
			j++;
		}
		if (flag)
			ft_rotate_a(data);
		else
			ft_push_b(data);
		i++;
	}
}

void	ft_five_sort(t_data_list *data)
{
	ft_push_b(data);
	ft_push_b(data);
	ft_three_sort(data);
	ft_sort_a(data);
	ft_sort_a(data);
	while (data->list_a->number != 1)
	{
		if (2 * data->list_a->number > data->a_qty)
			ft_rotate_a(data);
		else
			ft_r_rotate_a(data);
	}
}

void	ft_sort(t_data_list *data)
{
	if (ft_check_sorted(data->list_a, data->a_qty))
		return ;
	else if (data->a_qty == 2)
		ft_rotate_a(data);
	else if (data->a_qty == 3)
		ft_three_sort(data);
	else if (data->a_qty == 5)
		ft_five_sort(data);
	else
	{
		ft_lis_rotate(data);
		while (data->b_qty != 0)
			ft_sort_a(data);
		while (data->list_a->number != 1)
		{
			if (2 * data->list_a->number > data->a_qty)
				ft_rotate_a(data);
			else
				ft_r_rotate_a(data);
		}
	}
}
