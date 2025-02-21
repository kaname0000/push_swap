/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:02:24 by okaname           #+#    #+#             */
/*   Updated: 2025/02/18 20:10:17 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../libft/libft.h"

typedef struct s_command
{
	int				all;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_command;

typedef struct s_stack
{
	int				number;
	t_command		cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data_list
{
	int				*lis;
	t_stack			*list_a;
	int				a_qty;
	t_stack			*list_b;
	int				b_qty;
}					t_data_list;

void				ft_push_a(t_data_list *data);
void				ft_push_a2(t_data_list *data);
void				ft_push_b(t_data_list *data);
void				ft_push_b2(t_data_list *data);
void				ft_swap(t_stack **list, int qty);
void				ft_swap_a(t_data_list *data);
void				ft_swap_b(t_data_list *data);
void				ft_swap_s(t_data_list *data);
void				ft_swap_s2(t_data_list *data);
void				ft_rotate(t_stack **list, int qty);
void				ft_rotate_a(t_data_list *data);
void				ft_rotate_b(t_data_list *data);
void				ft_rotate_r(t_data_list *data);
void				ft_rotate_r2(t_data_list *data);
void				ft_r_rotate(t_stack **list, int qty);
void				ft_r_rotate_a(t_data_list *data);
void				ft_r_rotate_b(t_data_list *data);
void				ft_r_rotate_r(t_data_list *data);
void				ft_r_rotate_r2(t_data_list *data);

#endif