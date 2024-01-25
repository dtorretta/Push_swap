/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:49:59 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/15 19:13:06 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra (t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *newlast;
	t_list *oldlast;

	newlast = *head; //pointer to the 1st element
	newlast->next->prev = NULL; //2nd node prev is null cause will be the 1st
	*head = newlast->next; //2nd now is the 1st
	oldlast = ft_lstlast(*head); //pointer to the last one
	oldlast->next = newlast; //conect the last one next to the old 1st
	newlast->prev = oldlast;
	newlast->next = NULL; //new end must end in null
		
	ft_printf("ra\n");
}

void rb(t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *newlast;
	t_list *oldlast;

	newlast = *head;
	newlast->next->prev = NULL;
	*head = newlast->next;
	oldlast = ft_lstlast(*head);
	oldlast->next = newlast;
	newlast->prev = oldlast;
	newlast->next = NULL;
		
	ft_printf("rb\n");
}

void rr(t_list **head_a, t_list **head_b)
{
	if (*head_a == NULL || *head_b == NULL || (*head_a)->next == NULL || (*head_b)->next == NULL )
		return;

	t_list *newlast_a;
	t_list *newlast_b;
	t_list *oldlast_a;
	t_list *oldlast_b;

	newlast_a = *head_a;
	newlast_a->next->prev = NULL;
	*head_a = newlast_a->next;
	oldlast_a = ft_lstlast(*head_a);
	oldlast_a->next = newlast_a;
	newlast_a->prev = oldlast_a;
	newlast_a->next = NULL;

	newlast_b = *head_b;
	newlast_b->next->prev = NULL;
	*head_b = newlast_b->next;
	oldlast_b = ft_lstlast(*head_b);
	oldlast_b->next = newlast_b;
	newlast_b->prev = oldlast_b;
	newlast_b->next = NULL;
		
	ft_printf("rr\n");
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
	

// 	//Rotate A
// 	t_list *temp_a = stack_a;
// 	printf("rotate A \noriginal ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n");
	
// 	ra(&stack_a);
	
// 	temp_a = stack_a;
// 	printf("sorted ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n\n");

// 	//Rotate B
// 	t_list *temp_b = stack_b;
// 	printf("Rotate B\noriginal ");
// 	while (temp_b) 
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");
	
// 	rb(&stack_b);
	
// 	temp_b = stack_b;
// 	printf("sorted ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");

// 	//Rotate AB
// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	printf("Rotate AB\noriginal ");
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
	
// 	rr(&stack_a, &stack_b);
	
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