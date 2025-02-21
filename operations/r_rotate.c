/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:27 by okaname           #+#    #+#             */
/*   Updated: 2025/02/18 20:08:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_r_rotate(t_stack **list, int qty)
{
	if (qty != 0)
		(*list) = (*list)->prev;
}

void	ft_r_rotate_a(t_data_list *data)
{
	ft_r_rotate(&(data->list_a), data->a_qty);
	write(1, "rra\n", 4);
}

void	ft_r_rotate_b(t_data_list *data)
{
	ft_r_rotate(&(data->list_b), data->b_qty);
	write(1, "rrb\n", 4);
}

void	ft_r_rotate_r2(t_data_list *data)
{
	ft_r_rotate(&(data->list_a), data->a_qty);
	ft_r_rotate(&(data->list_b), data->b_qty);
}

void	ft_r_rotate_r(t_data_list *data)
{
	ft_r_rotate_r2(data);
	write(1, "rrr\n", 4);
}
