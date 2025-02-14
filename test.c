/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:09:15 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 20:09:20 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	int n, i;
	// ユーザーから生成する数字の数を入力
	printf("生成するランダムな数字の個数を入力してください: ");
	scanf("%d", &n);
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
