/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:56:16 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 21:03:18 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_swap_a(t_data_list *data)
{
	t_stack	*tmp;

	tmp = data->list_a->next;
	data->list_a->next = tmp->next;
	tmp->prev = data->list_a->prev;
	data->list_a->prev->next = tmp;
	data->list_a->prev = tmp;
	tmp->next = data->list_a;
	data->list_a->next->prev = data->list_a;
	data->list_a = tmp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_data_list *data)
{
	t_stack	*tmp;

	tmp = data->list_b->next;
	data->list_b->next = tmp->next;
	tmp->prev = data->list_b->prev;
	data->list_b->prev->next = tmp;
	data->list_b->prev = tmp;
	tmp->next = data->list_b;
	data->list_b->next->prev = data->list_b;
	data->list_b = tmp;
	write(1, "sb\n", 3);
}
