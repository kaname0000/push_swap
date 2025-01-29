/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:02:24 by okaname           #+#    #+#             */
/*   Updated: 2025/01/29 18:02:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data_list
{
	t_stack			*list_a;
	int				a_qty;
	t_stack			*list_b;
	int				b_qty;
}					t_data_list;

void				ft_push_a(t_data_list *data);
void				ft_push_b(t_data_list *data);
void				ft_swap_a(t_data_list *data);
void				ft_swap_b(t_data_list *data);
void				ft_rotate_a(t_data_list *data);
void				ft_rotate_b(t_data_list *data);
void				ft_r_rotate_a(t_data_list *data);
void				ft_r_rotate_b(t_data_list *data);

#endif