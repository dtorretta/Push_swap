/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 20:19:00 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

// instructions
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

// small_sort
void	sort_3(t_list **head);
void	sort_4(t_list **head_a, t_list **head_b);
void	sort_5(t_list **head_a, t_list **head_b);

// big_sort
void	bigsort(t_list **head_a, t_list **head_b);

// free
void	free_string(char **str);
void	free_stack(t_list **stack);
void	error(char *msg);

// checks
int		check(int argc, char **argv, int i);
int		is_sorted(t_list **stack);

// position_finder
int		find_position(t_list *head, long max);
int		rev_find_position(t_list *head, long max);
int		find_max_position(t_list *head);

// index
void	init_stack(t_list **stack, int argc, char **argv);
void	index_stack(t_list **head);
t_list	*get_min(t_list **head);

#endif
