/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:55:12 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/25 17:38:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **head)
{
	//ft_printf("teeeeest\n");//borrar
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *newfirst;
	t_list *newlast;
	
	if (ft_lstlast(*head) == NULL)
		return;
	
	newfirst = ft_lstlast(*head);
	newlast = newfirst->prev;
	newlast->next = NULL;
	ft_lstadd_front(head, newfirst);
	ft_printf("rra\n");
}
void rrb(t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *newfirst;
	t_list *newlast;
	
	newfirst = ft_lstlast(*head);
	newlast = newfirst->prev;
	newlast->next = NULL;
	ft_lstadd_front(head, newfirst);
	ft_printf("rrb\n");
}
void rrr(t_list **head_a, t_list **head_b)
{
	if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
		return;

	t_list *newfirst_a;
	t_list *newlast_a;
	t_list *newfirst_b;
	t_list *newlast_b;
	
	newfirst_a = ft_lstlast(*head_a);
	newlast_a = newfirst_a->prev;
	newlast_a->next = NULL;
	ft_lstadd_front(head_a, newfirst_a);

	newfirst_b = ft_lstlast(*head_b);
	newlast_b = newfirst_b->prev;
	newlast_b->next = NULL;
	ft_lstadd_front(head_b, newfirst_b);

	ft_printf("rrr\n");
}

// int main (void)
// {
// 	char array[3] = {1, 3, 2};
// 	char arrax[3] = {6, 8, 7};
	
// 	t_list *stack_a = NULL;
// 	t_list *stack_b = NULL;
// 	int i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		ft_lstadd_back(&stack_a, ft_lstnew(&array[i]));
// 		ft_lstadd_back(&stack_b, ft_lstnew(&arrax[i]));
// 		i++;
// 	}
	
// 	//RRotate A
// 	t_list *temp_a = stack_a;
// 	printf("rrotate A \noriginal ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n");
	
// 	rra(&stack_a);
	
// 	temp_a = stack_a;
// 	printf("sorted ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n\n");

// 	//RRotate B
// 	t_list *temp_b = stack_b;
// 	printf("Rrotate B\noriginal ");
// 	while (temp_b) 
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");
	
// 	rrb(&stack_b);
	
// 	temp_b = stack_b;
// 	printf("sorted ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");

// 	//RRotate AB
// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	printf("Rrotate AB\noriginal ");
// 	while (temp_a) 
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- ");
// 	while (temp_b) 
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");
	
// 	rrr(&stack_a, &stack_b);
	
// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	printf("sorted ");
// 	while (temp_a) 
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- ");
// 	while (temp_b) 
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");

// 	return(0);
// }