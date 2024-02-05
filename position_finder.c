/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:23:16 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 19:07:03 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list *head, long max)
{
	int	min_position;
	int	count;

	min_position = 1;
	count = 1;
	while (head)
	{
		if (head->index < max)
		{
			min_position = count;
			break ;
		}
		head = head->next;
		count++;
	}
	return (min_position); // no estoysegura que funcione si no encuentra
}

int	rev_find_position(t_list *head, long max)
{
	t_list	*current;
	int		min_position;
	int		count;
	long	size;

	min_position = 1;
	count = 1;
	size = ft_lstsize(head);
	current = ft_lstlast(head);
	while (count < size)
	{
		if (current->index < max)
		{
			min_position = count;
			break ;
		}
		current = current->prev;
		count++;
	}
	return (min_position);
}

int	find_max_position(t_list *head)
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
