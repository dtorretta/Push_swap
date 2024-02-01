/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 17:33:10 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//8 4 10 1 7 6 5  //segmentation fault in 7

static int is_sorted(t_list **stack)
{
	t_list *temp = *stack;
	
	while(temp && temp->next) 
		{
			if(temp->value > temp->next->value) //not sorted
				return(0);
			else //sorted
			{
				temp = temp->next;
				if(!temp->next)
				{
					free_stack(stack); //*deberia liberar stack b?
					break;
				}
			}
		}
	return(1);
}
// int find_max_position(t_list *head)
// {
// 	int max_value = head->value;
// 	int max_position = 1;
// 	int count = 1;

// 	while (head != NULL)
// 	{
// 		if (head->value > max_value)
// 		{
// 			max_value = head->value;
// 			max_position = count;
// 		}
// 		head = head->next;
// 		count++;
// 	}
// 	return (max_position);
// }
int find_min_position(t_list *head)
{
	int min_value = head->value;
	int min_position = 1;
	int count = 1;

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
// int rev_find_min_position(t_list *head)
// {
// 	t_list *bottom;
// 	bottom = ft_lstlast(head); 
// 	int min_value = bottom->value; 
// 	int min_position = 1;
// 	int count = 1;
	
// 	while (bottom) //?
// 	{
// 		if (bottom->value < min_value)
// 		{
// 			min_value = bottom->value;
// 			min_position = count;
// 		}
// 		bottom = bottom->prev;
// 		count++;
// 	}
// 	return (min_position);
// }

void sort_3(t_list **head)
{
	int min_position;
	t_list *first;
	t_list *second;
	t_list *third;
	
	min_position = find_min_position(*head);
	first = *head;
	second = first->next;
	third = second->next;
	if(min_position == 1)
	{
		ra(head);
		sa(head);
		rra(head);
	}
	else if(min_position == 2)
	{
		if(first->value < third->value)
			sa(head);
		else
			ra(head); 
	}
	else if(min_position == 3)
	{
		if(first->value < second->value)
			rra(head);
		else
		{	
			sa(head);
			rra(head);
		} 
	}
}
void sort_4(t_list **head_a, t_list **head_b)
{
	int min_position;
		
	min_position = find_min_position(*head_a);
	
	if(min_position == 2)
		sa(head_a);
	else if(min_position == 3)
	{
		ra(head_a);
		ra(head_a);
	}
	else if(min_position == 4)
		rra(head_a);
	if(is_sorted(head_a)) //sorted
		return;
	pb(head_a, head_b);//si no esta ordenado sigue
	sort_3(head_a);
	pa(head_a, head_b);
}
void sort_5(t_list **head_a, t_list **head_b)
{
	int min_position;
		
	min_position = find_min_position(*head_a);
	
	if(min_position == 2)
		sa(head_a);
	else if(min_position == 3)
	{
		ra(head_a);
		ra(head_a);
	}
	else if(min_position == 4)
	{
		rra(head_a);
		rra(head_a);
	}
	else if(min_position == 5)
		rra(head_a);
	if(is_sorted(head_a)) //sorted
		return;
	pb(head_a, head_b);//si no esta ordenado sigue
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}
// void ft_push_swap(t_list **head_a, t_list **head_b)
// {
// 	int min_position;
// 	int i;
// 	long size;

// 	size = ft_lstsize(*head_a);
// 	while(size > 0)
// 	{
// 		min_position = find_min_position(*head_a); //busco el numero mas chico y su position
// 		if (min_position <= (size/2 + 1)) //si minimo esta en la primera mitad
// 		{
// 			i = 1;
// 			while(i < min_position)
// 			{
// 				ra(head_a);
// 				i++;
// 			}
// 		}
// 		else //si minimo esta en la segunda mitad
// 		{
// 			i = ft_lstsize(*head_a);
// 			while(i >= min_position && i <= size)
// 			{
// 				rra(head_a); 
// 				i--;
// 			}
// 		}
// 		pb(head_a, head_b); 
// 		size--; 
// 	}
// 	while(ft_lstsize(*head_b) > 0)  //devolver todo a A
// 		pa(head_a, head_b);
// }

static void	ft_sort(t_list **stack_a, t_list **stack_b)
{//puedo ponerle static int y solo return???
	long size;

	size = ft_lstsize(*stack_a);
	// if(size == 1)
	// {
	// 	ft_printf("only one element\n");//borrar
	// 	return;
	// }
	if(size == 2)
		sa(stack_a);
	else if(size == 3)
		sort_3(stack_a);
	else if(size == 4)
		sort_4(stack_a, stack_b);
	else if(size == 5)
		sort_5(stack_a, stack_b);
	else if(size <= 100) 
		ft_big_sort(stack_a, stack_b);
	else
		sort_500(stack_a, stack_b);
}

static void	init_stack(t_list **stack, int argc, char **argv)
{
	char	**args;
	t_list	*new;
	int i;	
	
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}	
	
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	
	index_stack(stack); //ver
	
	if (argc == 2) //si arc = 2 entonces usamos split. split usa malloc y tengo que liberar la memoria. ya no me sirve args porque cree el stack
	{
		free_string(args);
	}
}
int main(int argc, char **argv)
{
	int i;
	t_list **stack_a;
	t_list **stack_b;
	
	i = 0;
	if(!check(argc, argv, i)) //checks
		return (EXIT_FAILURE);
	
	stack_a = (t_list **)malloc(sizeof(t_list)); //creacion stack A
	if (!stack_a)
		return (EXIT_FAILURE);
	*stack_a = NULL;

	init_stack(stack_a, argc, argv); //inicializar stack A
	if(is_sorted(stack_a)) //check si ya esta en orden
		return(EXIT_SUCCESS);
		
	stack_b = (t_list **)malloc(sizeof(t_list)); //creacion stack B
	if (!stack_b)
	{
		free_stack(stack_a); 
		return (EXIT_FAILURE);
	}
	*stack_b = NULL;
		
	ft_sort(stack_a, stack_b);
	free_stack(stack_a); //aca hay problemas
	free_stack(stack_b); 	
	return (0);
}
