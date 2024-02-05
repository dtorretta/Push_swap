/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:55:12 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 19:24:46 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **head)
{
	t_list	*newfirst;
	t_list	*newlast;

	if (*head == NULL || (*head)->next == NULL || ft_lstsize(*head) < 2)
		return ;
	if (ft_lstlast(*head) == NULL)
		return ;
	newfirst = ft_lstlast(*head);
	newlast = newfirst->prev;
	newlast->next = NULL;
	ft_lstadd_front(head, newfirst);
}

void	rra(t_list **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}
