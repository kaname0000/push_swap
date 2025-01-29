/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:12:58 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 23:52:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "operations/operations.h"
# include "stdio.h"
# include "stdlib.h"

t_data_list	*ft_make_list(int argc, char **argv);
t_stack		*ft_make_node(int number);
int			ft_check_duplicates(int *array, int len);
void		ft_sort(t_data_list *data);
void		ft_sort_b(t_data_list *data);
void		ft_sort_a(t_data_list *data);
int			*ft_compress(int *array, int len);
void		ft_print_data(t_data_list *data);

#endif