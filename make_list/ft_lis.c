/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:50:56 by okaname           #+#    #+#             */
/*   Updated: 2025/02/08 16:50:38 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*ft_int_array_cpy(int *array, int len)
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(len * sizeof(int));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}

static int	ft_array_max_index(int *array, int len, int *index)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < len)
	{
		if (max < array[i])
		{
			*index = i;
			max = array[i];
		}
		i++;
	}
	return (max);
}

static void	ft_make_dp_prev(int *array, int *dp, int *prev, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		dp[i] = 1;
		prev[i] = -1;
	}
	i = 0;
	while (++i < len)
	{
		j = -1;
		while (++j < i)
		{
			if (array[i] > array[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}
}

static int	*ft_make_lis(int *array, int *dp, int *prev, int len)
{
	int	*lis;
	int	i;
	int	max_dp;
	int	index;

	lis = ft_int_array_cpy(array, len);
	if (lis == NULL)
		return (NULL);
	max_dp = ft_array_max_index(dp, len, &index);
	i = len;
	while (i--)
	{
		if (i != index)
			lis[i] = 0;
		else
			index = prev[i];
	}
	return (lis);
}

int	*ft_lis(int *array, int len)
{
	int	*dp;
	int	*prev;
	int	*lis;

	dp = malloc(sizeof(int) * len);
	prev = malloc(sizeof(int) * len);
	if (dp == NULL || prev == NULL)
	{
		free(dp);
		free(prev);
		return (NULL);
	}
	ft_make_dp_prev(array, dp, prev, len);
	lis = ft_make_lis(array, dp, prev, len);
	if (lis == NULL)
	{
		free(dp);
		free(prev);
		return (NULL);
	}
	free(dp);
	free(prev);
	return (lis);
}

// int	main(void)
// {
// 	int	arr[] = {7, 12, 6, 17, 15, 2, 4, 16, 3, 10, 1, 18, 11, 13, 20, 5, 8, 9,
// 			14, 19};
// 	int	*lis;

// 	lis = ft_lis(arr, 20);
// 	for (int i = 0; i < 20; i++)
// 	{
// 		printf("%d,", lis[i]);
// 	}
// 	free(lis);
// 	return (0);
// }
