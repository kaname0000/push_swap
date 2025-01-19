/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:11:30 by okaname           #+#    #+#             */
/*   Updated: 2025/01/19 17:24:10 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*array;

	if (argc == 1)
		return (0);
	array = ft_make_array(argc, argv);
	if (array == NULL)
	{
		printf("segfa");
		return (0);
	}
	printf("%d", array[0]);
	return (0);
}

// int	answer(void)
// {
// 	return (OVERFLOW);
// }

// int	main(void)
// {
// 	int	ans;

// 	ans = answer();
// 	if (ans == 1)
// 		printf("ans = 1");
// 	if (ans == OVERFLOW)
// 		printf("ans =overflow");
// }
