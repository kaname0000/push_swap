/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:11:30 by okaname           #+#    #+#             */
/*   Updated: 2025/01/30 00:08:39 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_data(t_data_list *data)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	i = 0;
	tmp1 = data->list_a;
	tmp2 = data->list_b;
	printf("----------\n");
	printf("--list_a--\n");
	printf("a_qty = %d\n", data->a_qty);
	while (i < data->a_qty)
	{
		printf("%d\n", tmp1->number);
		tmp1 = tmp1->next;
		i++;
	}
	printf("--list_b--\n");
	i = 0;
	printf("b_qty = %d\n", data->b_qty);
	while (i < data->b_qty)
	{
		printf("%d\n", tmp2->number);
		tmp2 = tmp2->next;
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
		write(1, "error\n", 6);
		return (0);
	}
	ft_sort(data);
	ft_print_data(data);
	return (0);
}
