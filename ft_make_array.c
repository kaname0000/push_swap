/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:41:17 by okaname           #+#    #+#             */
/*   Updated: 2025/01/19 17:23:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_with_error(char *n, int *error_flag)
{
	int		i;
	long	num;
	int		sign;

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
				&& (-num < (LONG_MIN + (n[i] - '0')) / 10)))
			*error_flag = 1;
		num = num * 10 + (n[i++] - '0');
	}
	if (n[i] != '\0')
		*error_flag = 1;
	return ((int)num * sign);
}

int	*ft_char_to_int(char **strs)
{
	int	*array;
	int	i;
	int	error_flag;
	int	len;

	len = 0;
	while (strs[len] != NULL)
		len++;
	i = -1;
	error_flag = 0;
	array = malloc(len * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (strs[++i] != NULL)
		array[i] = ft_atoi_with_error(strs[i], &error_flag);
	printf("%d", error_flag);
	if (error_flag)
		return (NULL);
	return (array);
}

int	*ft_make_array(int count, char **argv)
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
			array_c[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		array_c[i] = NULL;
	}
	return (ft_char_to_int(array_c));
}
