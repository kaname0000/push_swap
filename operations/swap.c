/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:56:16 by okaname           #+#    #+#             */
/*   Updated: 2025/02/17 18:54:48 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_swap(t_stack **list, int qty)
{
	t_stack	*tmp;

	if (qty == 2)
		(*list) = (*list)->next;
	else
	{
		tmp = (*list)->next;
		(*list)->next = tmp->next;
		tmp->prev = (*list)->prev;
		(*list)->prev->next = tmp;
		(*list)->prev = tmp;
		tmp->next = (*list);
		(*list)->next->prev = (*list);
		(*list) = tmp;
	}
}

void	ft_swap_a(t_data_list *data)
{
	if (data->a_qty == 0 || data->a_qty == 1)
		return ;
	ft_swap(&(data->list_a), data->a_qty);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_data_list *data)
{
	if (data->b_qty == 0 || data->b_qty == 1)
		return ;
	ft_swap(&(data->list_b), data->b_qty);
	write(1, "sb\n", 3);
}

void	ft_swap_s2(t_data_list *data)
{
	if (!(data->a_qty == 0 || data->a_qty == 1))
		ft_swap(&(data->list_a), data->a_qty);
	if (!(data->a_qty == 0 || data->a_qty == 1))
		ft_swap(&(data->list_b), data->b_qty);
}

void	ft_swap_s(t_data_list *data)
{
	ft_swap_s2(data);
	write(1, "ss\n", 1);
}
