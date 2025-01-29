/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:15:09 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 18:41:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate_a(t_data_list *data)
{
	data->list_a = data->list_a->next;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_data_list *data)
{
	data->list_b = data->list_b->next;
	write(1, "rb\n", 3);
}

void	ft_r_rotate_a(t_data_list *data)
{
	data->list_a = data->list_a->prev;
	write(1, "rra\n", 4);
}

void	ft_r_rotate_b(t_data_list *data)
{
	data->list_b = data->list_b->prev;
	write(1, "rra\n", 4);
}
