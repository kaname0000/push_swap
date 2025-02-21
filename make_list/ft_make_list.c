/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:41:17 by okaname           #+#    #+#             */
/*   Updated: 2025/02/11 16:10:42 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_stack *list)
{
	t_stack	*tmp;
	t_stack	*current;

	if (list == NULL)
		return ;
	current = list;
	if (current->next == current)
	{
		free(current);
		list = NULL;
		return ;
	}
	while (current->next != list)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	list = NULL;
}

void	ft_free_list2(t_stack *list, int num)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (i < num)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		i++;
	}
}

static t_stack	*ft_make_stack(int *array, int qty)
{
	t_stack	*list_a;
	t_stack	*new_node;
	t_stack	*tmp;
	int		i;

	i = 0;
	list_a = ft_make_node(array[0]);
	if (list_a == NULL)
		return (NULL);
	tmp = list_a;
	while (++i < qty)
	{
		new_node = ft_make_node(array[i]);
		if (new_node == NULL)
		{
			ft_free_list2(list_a, i);
			return (NULL);
		}
		tmp->next = new_node;
		new_node->prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = list_a;
	list_a->prev = tmp;
	return (list_a);
}

t_data_list	*ft_make_list(int argc, char **argv)
{
	t_data_list	*data;
	int			*array_i;

	data = malloc(sizeof(t_data_list));
	if (data == NULL)
		return (NULL);
	data->a_qty = 0;
	array_i = ft_make_array2(argc, argv, &data->a_qty);
	if (array_i == NULL)
	{
		free(data);
		return (NULL);
	}
	data->lis = ft_lis(array_i, data->a_qty);
	data->list_a = ft_make_stack(array_i, data->a_qty);
	if (data->list_a == NULL || data->lis == NULL)
	{
		ft_free_data(data);
		free(array_i);
		return (NULL);
	}
	free(array_i);
	data->list_b = NULL;
	data->b_qty = 0;
	return (data);
}
