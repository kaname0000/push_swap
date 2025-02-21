/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:12:58 by okaname           #+#    #+#             */
/*   Updated: 2025/02/11 15:57:39 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "operations/operations.h"
# include "sort_algo/sort.h"
# include "stdio.h"
# include "stdlib.h"

t_data_list	*ft_make_list(int argc, char **argv);
t_stack		*ft_make_node(int number);
int			ft_check_duplicates(int *array, int len);
void		ft_free_strs(char **strs);
void		ft_free_list(t_stack *list);
int			*ft_lis(int *array, int len);
int			*ft_make_array2(int argc, char *argv[], int *qty);
void		ft_free_data(t_data_list *data);
int			*ft_compress(int *array, int len);
void		ft_print_data(t_data_list *data);

#endif