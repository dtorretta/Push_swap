/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:52 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:58 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **head)
{
	t_list	*firstnode;
	t_list	*secondnode;
	t_list	*thirdnode;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	firstnode = *head;
	secondnode = firstnode->next;
	thirdnode = secondnode->next;
	firstnode->next = thirdnode;
	if (thirdnode != NULL)
		thirdnode->prev = firstnode;
	ft_lstadd_front(head, secondnode);
}

void	sa(t_list **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}
