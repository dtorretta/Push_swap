/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:49:59 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 19:25:06 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **head)
{
	t_list	*newlast;
	t_list	*oldlast;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	newlast = *head;
	newlast->next->prev = NULL;
	*head = newlast->next;
	oldlast = ft_lstlast(*head);
	oldlast->next = newlast;
	newlast->prev = oldlast;
	newlast->next = NULL;
}

void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
