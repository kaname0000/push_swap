/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:32 by okaname           #+#    #+#             */
/*   Updated: 2025/02/07 04:18:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../operations/operations.h"
# include "../push_swap.h"

int		ft_check_sorted(t_stack *list, int len);
void	ft_sort(t_data_list *data);
void	ft_sort_b(t_data_list *data);
void	ft_sort_a(t_data_list *data);
int		ft_get_position_a(t_stack *list, int qty, int number);
int		ft_get_position_b(t_stack *list, int qty, int number);
void	ft_calculate_cost_a(t_data_list *data);
void	ft_calculate_cost_b(t_data_list *data);
int		ft_max_val(int x, int y);
int		ft_min_val(int x, int y);

#endif