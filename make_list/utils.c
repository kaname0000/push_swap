/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:19:13 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 18:03:21 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_make_node(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	ft_check_duplicates(int *array, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_compress(int *array, int len)
{
	int	rank;
	int	*new_array;
	int	i;
	int	j;

	new_array = malloc(sizeof(int) * len);
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rank = 1;
		j = 0;
		while (j < len)
		{
			if (array[i] > array[j])
				rank++;
			j++;
		}
		new_array[i] = rank;
		i++;
	}
	return (new_array);
}
