/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 17:21:58 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

int		check(int argc, char **argv, int i);
void	free_stack(t_list **stack);
void	free_string(char **str);

void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);

void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **head_a, t_list **head_b);

void	rra(t_list **head);
void	rrb(t_list **head);
void	rrr(t_list **head_a, t_list **head_b);

void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);

void ft_big_sort(t_list **head_a, t_list **head_b);
int		rev_find_min_position(t_list *head);
int		find_min_position(t_list *head);
int		find_max_position(t_list *head);
void sort_500(t_list **head_a, t_list **head_b);
void	index_stack(t_list **head);

#endif
