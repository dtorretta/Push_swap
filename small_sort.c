/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:47:18 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 20:50:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_list *head)
{
	int	min_value;
	int	min_position;
	int	count;

	min_value = head->value;
	min_position = 1;
	count = 1;
	while (head != NULL)
	{
		if (head->value < min_value)
		{
			min_value = head->value;
			min_position = count;
		}
		head = head->next;
		count++;
	}
	return (min_position);
}

void	sort_3(t_list **head)
{
	int		min_position;
	t_list	*first;

	min_position = find_min_position(*head);
	first = *head;
	if (min_position == 1)
	{
		ra(head);
		sa(head);
		rra(head);
	}
	else if (min_position == 2)
	{
		if (first->value < first->next->next->value)
			sa(head);
		else
			ra(head);
	}
	else
	{
		if (first->value > first->next->value)
			sa(head);
		rra(head);
	}
}

void	sort_4(t_list **head_a, t_list **head_b)
{
	int	min_position;

	min_position = find_min_position(*head_a);
	if (min_position == 2)
		sa(head_a);
	else if (min_position == 3)
	{
		ra(head_a);
		ra(head_a);
	}
	else if (min_position == 4)
		rra(head_a);
	if (is_sorted(head_a))
		return ;
	pb(head_a, head_b);
	sort_3(head_a);
	pa(head_a, head_b);
}

void	sort_5(t_list **head_a, t_list **head_b)
{
	int	min_position;

	min_position = find_min_position(*head_a);
	if (min_position == 2)
		sa(head_a);
	else if (min_position == 3)
	{
		ra(head_a);
		ra(head_a);
	}
	else if (min_position == 4)
	{
		rra(head_a);
		rra(head_a);
	}
	else if (min_position == 5)
		rra(head_a);
	if (is_sorted(head_a))
		return ;
	pb(head_a, head_b);
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}
