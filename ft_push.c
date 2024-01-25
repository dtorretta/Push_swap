/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:14:10 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/22 18:14:51 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **head_a, t_list **head_b)
{
	if (*head_b == NULL)
		return;

	t_list *newtop_b;

	newtop_b = (*head_b)->next; 
	ft_lstadd_front(head_a, *head_b);

	*head_b = newtop_b;
	if (newtop_b != NULL) 
		newtop_b->prev = NULL;

	ft_printf("pa\n");
}

void pb(t_list **head_a, t_list **head_b)
{
	if (*head_a == NULL)
		return;

	t_list *newtop_a;

	newtop_a = (*head_a)->next; 
	ft_lstadd_front(head_b, *head_a);

	*head_a = newtop_a;
	if (newtop_a != NULL) 
		newtop_a->prev = NULL;

	ft_printf("pb\n");
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
	

// 	//push A
// 	t_list *temp_a = stack_a;
// 	t_list *temp_b = stack_b;
// 	printf("Push A \nStack A original ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- Stack B original ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");
	
// 	pa(&stack_a, &stack_b);
	
// 	temp_a = stack_a;
// 	temp_b = stack_b;
	
// 	printf("Stack A ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- Stack B ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");

// 	//push B
// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	printf("Push A \nStack A original ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- Stack B original ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n\n");
	
// 	pb(&stack_a, &stack_b);
	
// 	temp_a = stack_a;
// 	temp_b = stack_b;
	
// 	printf("Stack A ");
// 	while (temp_a)
// 	{
// 		printf("%d ", *((char *)temp_a->value));
// 		temp_a = temp_a->next;
// 	}
// 	printf("- Stack B ");
// 	while (temp_b)
// 	{
// 		printf("%d ", *((char *)temp_b->value));
// 		temp_b = temp_b->next;
// 	}
// 	printf("\n");

// 	return(0);	
// }