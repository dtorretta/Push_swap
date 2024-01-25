/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:52 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/22 18:35:10 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *firstnode;
	t_list *secondnode;

	firstnode = *head; //pointer to 1st element
	secondnode = (*head)->next;	
	
	firstnode->next = secondnode->next; //conect next 1st with 3rd
	
	if (secondnode->next != NULL)
		secondnode->next->prev = firstnode->next; //conect prev
		
	ft_lstadd_front(head, secondnode);
	ft_printf("sa\n");
}	

void sb(t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	t_list *firstnode;
	t_list *secondnode;

	firstnode = *head;
	secondnode = (*head)->next;	
	
	firstnode->next = secondnode->next;
	if (secondnode->next != NULL)
		secondnode->next->prev = firstnode->next;
	
	ft_lstadd_front(head, secondnode);

	ft_printf("sb\n");
}	

void ss(t_list **head_a, t_list **head_b)
{
	if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
		return;

	t_list *firstnode_a;
	t_list *firstnode_b;
	t_list *secondnode_a;
	t_list *secondnode_b;

	firstnode_a = *head_a;
	secondnode_a = (*head_a)->next;	
	firstnode_a->next = secondnode_a->next;
	if (secondnode_a->next != NULL)
		secondnode_a->next->prev = firstnode_a->next;
	ft_lstadd_front(head_a, secondnode_a);

	firstnode_b = *head_b;
	secondnode_b = (*head_b)->next;	
	firstnode_b->next = secondnode_b->next;
	if (secondnode_b->next != NULL)
		secondnode_b->next->prev = firstnode_b->next;
	ft_lstadd_front(head_b, secondnode_b);

	ft_printf("ss\n");
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
	
// 	//swap A
// 	t_list *temp_a = stack_a;
// 	printf("swapA \noriginal ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n");
	
// 	sa(&stack_a);
	
// 	temp_a = stack_a;
// 	printf("sorted ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("\n\n");

// 	//swap B
// 	t_list *temp_b = stack_b;
// 	printf("swap B\noriginal ");
// 	while (temp_b) 
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");
	
// 	sb(&stack_b);
	
// 	temp_b = stack_b;
// 	printf("sorted ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");

// 	//swap AB
// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	printf("swap AB\noriginal ");
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
	
// 	ss(&stack_a, &stack_b);
	
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