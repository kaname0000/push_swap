/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:45:09 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 21:47:09 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_push_a(t_data_list *data)
{
	t_stack	*tmp;

	data->a_qty++;
	data->b_qty--;
	data->list_b->next->prev = data->list_b->prev;
	data->list_b->prev->next = data->list_b->next;
	tmp = data->list_b->next;
	if (data->b_qty == 0)
		tmp = NULL;
	if (data->list_a == NULL)
	{
		data->list_a = data->list_b;
		data->list_a->next = data->list_a;
		data->list_a->prev = data->list_a;
		data->list_b = tmp;
		write(1, "pa\n", 3);
		return ;
	}
	data->list_b->next = data->list_a;
	data->list_b->prev = data->list_a->prev;
	data->list_a->prev = data->list_b;
	data->list_b->prev->next = data->list_b;
	data->list_a = data->list_b;
	data->list_b = tmp;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_data_list *data)
{
	t_stack	*tmp;

	data->b_qty++;
	data->a_qty--;
	data->list_a->next->prev = data->list_a->prev;
	data->list_a->prev->next = data->list_a->next;
	tmp = data->list_a->next;
	if (data->a_qty == 0)
		tmp = NULL;
	if (data->list_b == NULL)
	{
		data->list_b = data->list_a;
		data->list_b->next = data->list_b;
		data->list_b->prev = data->list_b;
		data->list_a = tmp;
		write(1, "pb\n", 3);
		return ;
	}
	data->list_a->next = data->list_b;
	data->list_a->prev = data->list_b->prev;
	data->list_b->prev = data->list_a;
	data->list_a->prev->next = data->list_a;
	data->list_b = data->list_a;
	data->list_a = tmp;
	write(1, "pb\n", 3);
}
