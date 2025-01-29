/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:41:17 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 18:29:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_atoi_with_error(char *n, int *error_flag)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if ((n[i] == '+') || (n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(n[i]))
	{
		if ((sign == 1 && (num > (INT_MAX - (n[i] - '0')) / 10)) || (sign == -1
				&& (-num < (INT_MIN + (n[i] - '0')) / 10)))
			*error_flag = 1;
		num = num * 10 + (n[i++] - '0');
	}
	if (n[i] != '\0')
		*error_flag = 1;
	return ((int)num * sign);
}

static int	*ft_char_to_int(char **strs, int *len)
{
	int	*array;
	int	i;
	int	error_flag;

	while (strs[*len] != NULL)
		(*len)++;
	i = -1;
	error_flag = 0;
	array = malloc((*len) * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (strs[++i] != NULL)
		array[i] = ft_atoi_with_error(strs[i], &error_flag);
	if (error_flag)
		return (NULL);
	return (array);
}

static char	**ft_make_array(int count, char **argv)
{
	char	**array_c;
	int		i;

	i = 0;
	if (count == 2)
	{
		array_c = ft_split(argv[1], ' ');
		if (array_c == NULL)
			return (NULL);
	}
	else
	{
		array_c = malloc(count * sizeof(char *));
		if (array_c == NULL)
			return (NULL);
		while (i < count - 1)
		{
			array_c[i] = argv[i + 1];
			i++;
		}
		array_c[i] = NULL;
	}
	return (array_c);
}

static t_stack	*ft_make_stack(int *array, int qty)
{
	t_stack	*list_a;
	t_stack	*new_node;
	t_stack	*tmp;
	int		i;

	i = 1;
	list_a = ft_make_node(array[0]);
	if (list_a == NULL)
		return (NULL);
	tmp = list_a;
	while (i < qty)
	{
		new_node = ft_make_node(array[i]);
		if (new_node == NULL)
			return (NULL);
		tmp->next = new_node;
		new_node->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = list_a;
	list_a->prev = tmp;
	return (list_a);
}

t_data_list	*ft_make_list(int argc, char **argv)
{
	t_data_list	*data;
	char		**array_c;
	int			*array_i;
	int			*tmp;

	data = malloc(sizeof(t_data_list));
	if (data == NULL)
		return (NULL);
	data->a_qty = 0;
	array_c = ft_make_array(argc, argv);
	if (array_c == NULL)
		return (NULL);
	tmp = ft_char_to_int(array_c, &(data->a_qty));
	array_i = ft_compress(tmp, data->a_qty);
	if (array_i == NULL || ft_check_duplicates(array_i, data->a_qty))
		return (NULL);
	data->list_a = ft_make_stack(array_i, data->a_qty);
	if (data->list_a == NULL)
		return (NULL);
	data->list_b = NULL;
	data->b_qty = 0;
	return (data);
}
