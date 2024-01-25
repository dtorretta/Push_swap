/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/25 16:51:48 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//8 4 10 1 7 6 5  //segmentation fault in 7
static int find_min_position(t_list *head)
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
void ft_push_swap(t_list **head_a, t_list **head_b)
{
	int min_position;
	int i;
	long size;

	size = ft_lstsize(*head_a);
	while(size > 0)
	{
		min_position = find_min_position(*head_a); //busco el numero mas chico y su position
		if (min_position <= (size/2 + 1)) //si minimo esta en la primera mitad
		{
			i = 1;
			while(i < min_position)
			{
				ra(head_a);
				i++;
			}
		}
		else //si minimo esta en la segunda mitad
		{
			i = ft_lstsize(*head_a);
			while(i >= min_position && i <= size)
			{
				rra(head_a); 
				i--;
			}
		}
		pb(head_a, head_b); 
		size--; 
	}
	while(ft_lstsize(*head_b) > 0)  //devolver todo a A
		pa(head_a, head_b);
}
static void	ft_sort(t_list **stack_a, t_list **stack_b) //puedo ponerle static int y solo return???
{
	long size;

	size = ft_lstsize(*stack_a);
	if(size == 1)
	{
		ft_printf("only one element\n");
		return;
	}
	else 
		ft_push_swap(stack_a, stack_b); //crear para 3 casos / para 5 casos y etc
}

static int is_sorted(t_list **stack)
{
	t_list *temp = *stack;
	
	while(temp && temp->next) 
		{
			if(temp->value > temp->next->value) // **ATOI
			{
				//ft_printf("not sorted\n"); //borrar
				break;
			}
			else
			{
				//ft_printf("temp->value %d\n", temp->value); //borrar
				//ft_printf("temp->next->value %d\n", temp->next->value); //borrar
				temp = temp->next;
				if(!temp->next)
				{
					//ft_printf("sorted\n"); //borrar
					free_stack(stack);
					return(0);
				}
			}
		}
		//ft_printf("out the loop\n"); //borrar. cuando sale del loop ya esta listo para crear el stack b y empezar a ordenar.
		return(1);
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
	if(!is_sorted(stack_a)) //check si ya esta en orden
		return(EXIT_SUCCESS);
		
	stack_b = (t_list **)malloc(sizeof(t_list)); //creacion stack B
	if (!stack_b)
	{
		free_stack(stack_a); 
		return (EXIT_FAILURE);
	}
	*stack_b = NULL;
		
	ft_sort(stack_a, stack_b);
	free_stack(stack_a); 
	free_stack(stack_b); 	
	return (0);
}
