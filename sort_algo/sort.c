/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:04:21 by okaname           #+#    #+#             */
/*   Updated: 2025/01/30 00:22:34 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include "../push_swap.h"

static int	ft_check_sorted(t_stack *list, int len)
{
	int		num;
	t_stack	*tmp;
	int		i;

	i = 0;
	num = list->number;
	tmp = list->next;
	while (i < len - 1)
	{
		if (num > tmp->number)
			return (0);
		num = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static void	ft_three_sort(t_data_list *data)
{
	if (ft_check_sorted(data->list_a, 3))
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

void	ft_sort(t_data_list *data)
{
	if (ft_check_sorted(data->list_a, data->a_qty))
		return ;
	if (data->a_qty == 2)
		ft_swap_a(data);
	else if (data->a_qty == 3)
		ft_three_sort(data);
	else
	{
		ft_push_b(data);
		while (data->a_qty != 3 && data->b_qty <= (data->a_qty - 1))
			ft_sort_b(data);
		while (data->a_qty != 3)
			ft_push_b(data);
		ft_three_sort(data);
		while (data->b_qty != 0)
			ft_sort_a(data);
	}
}
