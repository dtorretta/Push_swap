/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:39 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/12 16:45:50 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*searchs the position of the biggest index*/
static int	find_max_position(t_list *head)
{
	int	max_index;
	int	max_position;
	int	count;

	max_index = -1;
	max_position = 1;
	count = 1;
	while (head != NULL)
	{
		if (head->index > max_index)
		{
			max_index = head->index;
			max_position = count;
		}
		head = head->next;
		count++;
	}
	return (max_position);
}

/*when all nodes are in stack B, this function looks for the biggest index
and push it one by one to Stak A*/
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

/*This function takes the first element of stack A. If it is not within the
specified interval, it reverses the stack. Otherwise, it pushes the node 
to stack B. In stack B, it considers whether the index is smaller than half of
the interval. In that case, it reverses the stack to leave it at the bottom*/
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
