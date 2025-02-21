/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:08:13 by okaname           #+#    #+#             */
/*   Updated: 2025/02/11 15:57:44 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_atoi_with_error(char *n, int *error_flag)
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
	{
		free(array);
		return (NULL);
	}
	ft_free_strs(strs);
	strs = NULL;
	return (array);
}

static char	**ft_make_array3(int count, char **argv)
{
	char	**array_c;
	int		i;

	i = 0;
	array_c = malloc(count * sizeof(char *));
	if (array_c == NULL)
		return (NULL);
	while (i < count - 1)
	{
		array_c[i] = ft_strdup(argv[i + 1]);
		if (array_c[i] == NULL)
		{
			ft_free_strs(array_c);
			return (NULL);
		}
		i++;
	}
	array_c[i] = NULL;
	return (array_c);
}

static char	**ft_make_array(int count, char **argv)
{
	char	**array_c;

	if (count == 2)
	{
		array_c = ft_split(argv[1], ' ');
		if (array_c == NULL)
			return (NULL);
		if (array_c[0] == NULL)
		{
			ft_free_strs(array_c);
			return (NULL);
		}
	}
	else
	{
		array_c = ft_make_array3(count, argv);
		if (array_c == NULL)
			return (NULL);
	}
	return (array_c);
}

int	*ft_make_array2(int argc, char *argv[], int *qty)
{
	char	**array_c;
	int		*array_i;
	int		*tmp;

	array_c = ft_make_array(argc, argv);
	if (array_c == NULL)
		return (NULL);
	tmp = ft_char_to_int(array_c, qty);
	if (tmp == NULL)
	{
		ft_free_strs(array_c);
		return (NULL);
	}
	if (ft_check_duplicates(tmp, *qty))
	{
		free(tmp);
		return (NULL);
	}
	array_i = ft_compress(tmp, *qty);
	if (array_i == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return (array_i);
}
