/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:15:09 by okaname           #+#    #+#             */
/*   Updated: 2025/02/18 20:10:05 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate(t_stack **list, int qty)

{
	if (qty != 0)
		(*list) = (*list)->next;
}

void	ft_rotate_a(t_data_list *data)
{
	ft_rotate(&(data->list_a), data->a_qty);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_data_list *data)
{
	ft_rotate(&(data->list_b), data->b_qty);
	write(1, "rb\n", 3);
}

void	ft_rotate_r2(t_data_list *data)
{
	ft_rotate(&(data->list_a), data->a_qty);
	ft_rotate(&(data->list_b), data->b_qty);
}

void	ft_rotate_r(t_data_list *data)
{
	ft_rotate_r2(data);
	write(1, "rr\n", 3);
}
