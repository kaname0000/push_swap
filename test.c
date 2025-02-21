/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:09:15 by okaname           #+#    #+#             */
/*   Updated: 2025/02/08 19:39:47 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	int n, i;
	// ユーザーから生成する数字の数を入力
	n = atoi(argv[1]);
	// 乱数の種を現在の時間に基づいて初期化
	srand(time(NULL));
	// ランダムな数字の列を生成して出力
	printf("ランダムな数字の列:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", rand()); // rand() でランダムな整数を出力
	}
	printf("\n");
	return (0);
}

// void	ft_update_cost3(t_command *cost)
// {
// 	if (cost->ra < cost->rb)
// 	{
// 		cost->ra = cost->rr;
// 		cost->rb = 0;
// 		cost->rr = 0;
// 	}
// 	else
// 	{
// 		cost->rb = cost->rr;
// 		cost->ra = 0;
// 		cost->rr = 0;
// 	}
// 	if (cost->rra < cost->rrb)
// 	{
// 		cost->rra = cost->rrr;
// 		cost->rrb = 0;
// 		cost->rrr = 0;
// 	}
// 	else
// 	{
// 		cost->rrb = cost->rrr;
// 		cost->rra = 0;
// 		cost->rrr = 0;
// 	}
// }
// printf("all = %d\n", cost.all);
// printf("ra = %d\n", cost.ra);
// printf("rb = %d\n", cost.rb);
// printf("rr = %d\n", cost.rr);
// printf("rra = %d\n", cost.rra);
// printf("rrb = %d\n", cost.rrb);
// printf("rrr = %d\n", cost.rrr);
