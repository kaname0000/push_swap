/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:17 by okaname           #+#    #+#             */
/*   Updated: 2025/02/07 03:32:15 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ft_run_command(t_command cost, t_data_list *data)
{
	while (cost.ra--)
		ft_rotate_a(data);
	while (cost.rb--)
		ft_rotate_b(data);
	while (cost.rr--)
		ft_rotate_r(data);
	while (cost.rra--)
		ft_r_rotate_a(data);
	while (cost.rrb--)
		ft_r_rotate_b(data);
	while (cost.rrr--)
		ft_r_rotate_r(data);
}

int	ft_get_position_b(t_stack *list, int qty, int number)
{
	int		index;
	t_stack	*tmp;
	int		nub;

	nub = 0;
	index = 1;
	tmp = list;
	while (index < (qty + 1))
	{
		if ((number) < (tmp->number) && (number) > tmp->next->number)
			break ;
		if ((tmp->number) < tmp->next->number)
			nub = index;
		tmp = tmp->next;
		index++;
	}
	if (index == (qty + 1))
		index = nub;
	if (nub == qty)
		index = 0;
	return (index);
}

int	ft_get_position_a(t_stack *list, int qty, int number)
{
	int		index;
	t_stack	*tmp;
	int		nub;

	nub = 0;
	index = 1;
	tmp = list;
	while (index < (qty + 1))
	{
		if ((number) > (tmp->number) && (number) < tmp->next->number)
			break ;
		if ((tmp->number) > tmp->next->number)
			nub = index;
		tmp = tmp->next;
		index++;
	}
	if (index == (qty + 1))
		index = nub;
	if (nub == qty)
		index = 0;
	return (index);
}

void	ft_sort_b(t_data_list *data)
{
	int			min;
	int			i;
	t_command	cost;

	if (data->b_qty == 1)
	{
		ft_push_b(data);
		return ;
	}
	min = data->a_qty + data->b_qty;
	i = 0;
	ft_calculate_cost_a(data);
	while (i < data->a_qty)
	{
		if (min > data->list_a->cost.all)
		{
			min = data->list_a->cost.all;
			cost = data->list_a->cost;
		}
		data->list_a = data->list_a->next;
		i++;
	}
	ft_run_command(cost, data);
	ft_push_b(data);
}

void	ft_sort_a(t_data_list *data)
{
	int			min;
	int			i;
	t_command	cost;

	min = data->a_qty + data->b_qty;
	i = 0;
	ft_calculate_cost_b(data);
	while (i < data->b_qty)
	{
		if (min > data->list_b->cost.all)
		{
			min = data->list_b->cost.all;
			cost = data->list_b->cost;
		}
		data->list_b = data->list_b->next;
		i++;
	}
	ft_run_command(cost, data);
	ft_push_a(data);
}
