/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:07:32 by okaname           #+#    #+#             */
/*   Updated: 2025/02/08 22:35:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include "../push_swap.h"
#include "sort.h"

static void	ft_update_cost1(t_command *cost);
static void	ft_update_cost2(t_command *cost);

void	ft_calculate_cost_a(t_data_list *data)
{
	int	a;
	int	b;

	a = 0;
	while (a < data->a_qty)
	{
		b = ft_get_position_b(data->list_b, data->b_qty, data->list_a->number);
		data->list_a->cost.ra = a - ft_min_val(a, b);
		data->list_a->cost.rb = b - ft_min_val(a, b);
		data->list_a->cost.rr = ft_min_val(a, b);
		data->list_a->cost.rra = data->a_qty - a - ft_min_val(data->a_qty - a,
				data->b_qty - b);
		data->list_a->cost.rrb = data->b_qty - b - ft_min_val(data->a_qty - a,
				data->b_qty - b);
		data->list_a->cost.rrr = ft_min_val(data->a_qty - a, data->b_qty - b);
		ft_update_cost1(&(data->list_a->cost));
		a++;
		data->list_a = data->list_a->next;
	}
}

void	ft_calculate_cost_b(t_data_list *data)
{
	int	a;
	int	b;

	b = 0;
	while (b < data->b_qty)
	{
		a = ft_get_position_a(data->list_a, data->a_qty, data->list_b->number);
		data->list_b->cost.ra = a - ft_min_val(a, b);
		data->list_b->cost.rb = b - ft_min_val(a, b);
		data->list_b->cost.rr = ft_min_val(a, b);
		data->list_b->cost.rra = data->a_qty - a - ft_min_val(data->a_qty - a,
				data->b_qty - b);
		data->list_b->cost.rrb = data->b_qty - b - ft_min_val(data->a_qty - a,
				data->b_qty - b);
		data->list_b->cost.rrr = ft_min_val(data->a_qty - a, data->b_qty - b);
		ft_update_cost1(&(data->list_b->cost));
		b++;
		data->list_b = data->list_b->next;
	}
}

static void	ft_update_cost1(t_command *cost)
{
	if ((cost->ra + cost->rb + cost->rr <= cost->rra + cost->rrb + cost->rrr)
		&& (cost->ra + cost->rb + cost->rr) <= (cost->ra + cost->rrb + cost->rr
			+ cost->rrr) && (cost->ra + cost->rb + cost->rr) <= (cost->rb
			+ cost->rra + cost->rr + cost->rrr))
	{
		cost->all = cost->ra + cost->rb + cost->rr;
		cost->rra = 0;
		cost->rrb = 0;
		cost->rrr = 0;
	}
	else if ((cost->ra + cost->rb + cost->rr >= cost->rra + cost->rrb
			+ cost->rrr) && (cost->rra + cost->rrb + cost->rrr) <= (cost->ra
			+ cost->rrb + cost->rr + cost->rrr) && (cost->rra + cost->rrb
			+ cost->rrr) <= (cost->rb + cost->rra + cost->rr + cost->rrr))
	{
		cost->all = cost->rra + cost->rrb + cost->rrr;
		cost->ra = 0;
		cost->rb = 0;
		cost->rr = 0;
	}
	else
	{
		cost->all = cost->rr + cost->rrr;
		ft_update_cost2(cost);
	}
}

static void	ft_update_cost2(t_command *cost)
{
	if (cost->ra < cost->rb)
	{
		cost->ra = cost->rr;
		cost->rb = 0;
		cost->rr = 0;
	}
	else
	{
		cost->rb = cost->rr;
		cost->ra = 0;
		cost->rr = 0;
	}
	if (cost->rra < cost->rrb)
	{
		cost->rra = cost->rrr;
		cost->rrb = 0;
		cost->rrr = 0;
	}
	else
	{
		cost->rrb = cost->rrr;
		cost->rra = 0;
		cost->rrr = 0;
	}
}
