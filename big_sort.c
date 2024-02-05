/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:39 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 20:04:57 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sortb(t_list **head_a, t_list **head_b)
{
	int		max_position;
	long	size_b;

	size_b = ft_lstsize(*head_b);
	while (size_b > 0)
	{
		max_position = find_max_position(*head_b);
		if (max_position <= (size_b / 2 + 1))
		{
			while (max_position-- > 1)
				rb(head_b);
		}
		else
		{
			while (size_b >= max_position++)
				rrb(head_b);
		}
		pa(head_a, head_b);
		size_b--;
	}
}

void	bigsort(t_list **head_a, t_list **head_b)
{
	int	interval_size;
	int	interval_count;
	int	i;

	interval_size = (ft_lstsize(*head_a) / 10) + 10;
	interval_count = 1;
	i = 0;
	while (ft_lstsize(*head_a))
	{
		if ((*head_a)->index < (interval_count * interval_size))
		{
			pb(head_a, head_b);
			if ((*head_b)->index
				< (interval_count * interval_size) - (interval_size / 2))
				rb(head_b);
			i++;
		}
		else
			ra(head_a);
		if (i == (interval_count * interval_size))
			interval_count++;
	}
	sortb(head_a, head_b);
}
