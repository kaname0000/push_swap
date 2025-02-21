/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:11:30 by okaname           #+#    #+#             */
/*   Updated: 2025/02/21 16:43:01 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_data(t_data_list *data)
{
	int	i;

	i = 0;
	printf("----------\n");
	printf("--list_a--\n");
	printf("a_qty = %d\n", data->a_qty);
	while (i < data->a_qty)
	{
		printf("%d\n", data->list_a->number);
		data->list_a = data->list_a->next;
		i++;
	}
	printf("--list_b--\n");
	i = 0;
	printf("b_qty = %d\n", data->b_qty);
	while (i < data->b_qty)
	{
		printf("%d\n", data->list_b->number);
		// printf("all = %d\n", data->list_b->cost.all);
		// printf("ra = %d\n", data->list_b->cost.ra);
		// printf("rb = %d\n", data->list_b->cost.rb);
		// printf("rr = %d\n", data->list_b->cost.rr);
		// printf("rra = %d\n", data->list_b->cost.rra);
		// printf("rrb = %d\n", data->list_b->cost.rrb);
		// printf("rrr = %d\n", data->list_b->cost.rrr);
		data->list_b = data->list_b->next;
		i++;
	}
	printf("----------\n");
}

int	main(int argc, char *argv[])
{
	t_data_list	*data;

	if (argc == 1)
		return (0);
	data = ft_make_list(argc, argv);
	if (data == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_sort(data);
	ft_free_data(data);
	return (0);
}
