/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:17 by okaname           #+#    #+#             */
/*   Updated: 2025/01/30 00:23:26 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"

static int	ft_get_position_b(t_data_list *data)
{
	int		index;
	t_stack	*tmp;
	int		nub;

	index = 1;
	tmp = data->list_b;
	while (index < (data->b_qty + 1))
	{
		if ((data->list_a->number) < (tmp->number)
			&& (data->list_a->number) > tmp->next->number)
			break ;
		if ((tmp->number) < tmp->next->number)
			nub = index;
		tmp = tmp->next;
		index++;
	}
	if (index == (data->b_qty + 1))
		index = nub;
	return (index);
}

void	ft_sort_b(t_data_list *data)
{
	int	index;

	index = ft_get_position_b(data);
	if ((2 * index) > data->b_qty)
	{
		while (index++ < data->b_qty)
			ft_r_rotate_b(data);
	}
	else
	{
		while (index--)
			ft_rotate_b(data);
	}
	ft_push_b(data);
}

static int	ft_get_position_a(t_data_list *data)
{
	int		index;
	t_stack	*tmp;
	int		nub;

	index = 1;
	tmp = data->list_a;
	while (index < (data->a_qty + 1))
	{
		if ((data->list_b->number) < (tmp->number)
			&& (data->list_b->number) > tmp->next->number)
			break ;
		if ((tmp->number) < tmp->next->number)
			nub = index;
		tmp = tmp->next;
		index++;
	}
	if (index == (data->a_qty + 1))
		index = nub;
	return (index);
}

void	ft_sort_a(t_data_list *data)
{
	int	index;

	index = ft_get_position_a(data);
	printf("%d\n", index);
	if ((2 * index) > data->a_qty)
	{
		while (index++ < data->a_qty)
			ft_r_rotate_a(data);
	}
	else
	{
		while (index--)
			ft_rotate_a(data);
	}
	ft_push_a(data);
}
