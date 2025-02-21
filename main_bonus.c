/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:28:59 by okaname           #+#    #+#             */
/*   Updated: 2025/02/19 15:40:04 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_run_ope(t_data_list *data, char *line)
{
	if (ft_strncmp("ra\n", line, 5) == 0)
		ft_rotate(&(data->list_a), data->a_qty);
	else if (ft_strncmp("rb\n", line, 5) == 0)
		ft_rotate(&(data->list_b), data->b_qty);
	else if (ft_strncmp("rr\n", line, 5) == 0)
		ft_rotate_r2(data);
	else if (ft_strncmp("rra\n", line, 5) == 0)
		ft_r_rotate(&(data->list_a), data->a_qty);
	else if (ft_strncmp("rrb\n", line, 5) == 0)
		ft_r_rotate(&(data->list_b), data->b_qty);
	else if (ft_strncmp("rrr\n", line, 5) == 0)
		ft_r_rotate_r2(data);
	else if (ft_strncmp("sa\n", line, 5) == 0)
		ft_swap(&(data->list_a), data->a_qty);
	else if (ft_strncmp("sb\n", line, 5) == 0)
		ft_swap(&(data->list_b), data->b_qty);
	else if (ft_strncmp("ss\n", line, 5) == 0)
		ft_swap_s2(data);
	else if (ft_strncmp("pa\n", line, 5) == 0)
		ft_push_a2(data);
	else if (ft_strncmp("pb\n", line, 5) == 0)
		ft_push_b2(data);
	else
		return (1);
	return (0);
}

int	ft_get_stdin(t_data_list **data)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_run_ope((*data), line))
		{
			write(1, "Error\n", 6);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data_list	*data;

	if (argc == 1)
		return (0);
	data = ft_make_list(argc, argv);
	if (data == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_get_stdin(&data))
	{
		ft_free_data(data);
		return (0);
	}
	if (ft_check_sorted(data->list_a, data->a_qty) && data->b_qty == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_data(data);
	return (0);
}
