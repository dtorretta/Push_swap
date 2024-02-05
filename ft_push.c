/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:14:10 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 19:25:21 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **head_a, t_list **head_b)
{
	t_list	*newtop_b;

	if (*head_b == NULL)
		return ;
	newtop_b = (*head_b)->next;
	ft_lstadd_front(head_a, *head_b);
	*head_b = newtop_b;
	if (newtop_b != NULL)
		newtop_b->prev = NULL;
}

void	pa(t_list **head_a, t_list **head_b)
{
	push(head_a, head_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **head_a, t_list **head_b)
{
	push(head_b, head_a);
	write(1, "pb\n", 3);
}
