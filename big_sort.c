/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:39 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 17:40:22 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rev_find_position(t_list *head, long max)
{
	t_list *current;
	current = ft_lstlast(head); 
	int min_position = 1; //???
	int count = 1;
	long size = ft_lstsize(head);
	
	while (count < size)
	{
		if (current->value < max)
		{
			min_position = count;
			break;
		}
		current = current->prev;
		count++;
	}
	return (min_position);
}
int find_position(t_list *head, long max)
{
	int min_position = 1;
	int count = 1;
	
	while (head != NULL)
	{
		if (head->value < max)
		{
			min_position = count;
			break;
		}
		head = head->next;
		count++;
	}
	return (min_position); //no estoysegura que funcione si no encuentra
}
int find_position500(t_list *head, long max)
{
	int min_position = 1;
	int count = 1;
	
	while (head)
	{
		if (head->index < max) //index
		{
			min_position = count;
			break;
		}
		head = head->next;
		count++;
	}
	return (min_position); //no estoysegura que funcione si no encuentra
}
int rev_find_position500(t_list *head, long max)
{
	t_list *current;
	current = ft_lstlast(head); 
	int min_position = 1; //???
	int count = 1;
	long size = ft_lstsize(head);
	
	while (count < size)
	{
		if (current->index < max)
		{
			min_position = count;
			break;
		}
		current = current->prev;
		count++;
	}
	return (min_position);
}
int find_max_position(t_list *head)
{
	int max_value = head->value;
	int max_position = 1;
	int count = 1;

	while (head != NULL)
	{
		if (head->value > max_value)
		{
			max_value = head->value;
			max_position = count;
		}
		head = head->next;
		count++;
	}
	return (max_position);
}
int find_max_position500(t_list *head)
{
	int max_index = head->index;
	int max_position = 1;
	int count = 1;

	while (head)
	{
		if (head->index > max_index)
		{
			max_index = head->value;
			max_position = count;
		}
		head = head->next; //deberia agregar un t_list *current???
		count++;
	}
	return (max_position);
}
void ft_big_sort(t_list **head_a, t_list **head_b)
{
	int min_position;
	int min_position_down;
	int max_position;
	int i;
	long size_a;
	long size_b;
	int substack;
	long max = 20;

	size_a = ft_lstsize(*head_a);
	while(size_a > 0)
	{
		substack = 0;
		while(substack < max) //buscar numeros del 0 a 20 que son el grupo 1
		{
			min_position = find_position(*head_a, max); //busco el numero mas chico y su position empezando de arriba
			min_position_down = rev_find_position(*head_a, max); //empezando de abajo

				if (min_position <= min_position_down) //si minimo esta en la primera mitad 
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
				i = min_position_down;
				while(i > 0)
				{
					rra(head_a); 
					i--;
				}
			}
			pb(head_a, head_b);
			size_a --;
			substack ++;
		}
		max += 20;
	}	
	
	//ACA DEBERIA ORDENAR B
	size_b = ft_lstsize(*head_b);
	while(size_b > 0)
	{
		max_position = find_max_position(*head_b);
		if (max_position <= (size_b/2 + 1)) //si maximo esta en la primera mitad
		{
			i = 1;
			while(i < max_position)
			{
				rb(head_b);
				i++;
			}
		}
		else //si maximo esta en la segunda mitad
		{
			i = ft_lstsize(*head_b);
			while(i >= max_position)
			{
				rrb(head_b); 
				i--;
			}
		}
		pa(head_a, head_b); 
		size_b--;
	}

}
void sort_500(t_list **head_a, t_list **head_b)
{
	int min_position;
	int min_position_down;
	int max_position;
	int i;
	long size_a;
	long size_b;
	int substack;
	long max = 25;

	size_a = ft_lstsize(*head_a);
	while(size_a > 0)
	{
		substack = 0;
		while(substack < max) //buscar numeros del 0 a 20 que son el grupo 1
		{
			min_position = find_position500(*head_a, max);
			min_position_down = rev_find_position500(*head_a, max); 
			//min_position = find_position500(*head_a, max); //busco el numero mas chico y su position empezando de arriba
			//min_position_down = rev_find_position(*head_a, max); //empezando de abajo

			if (min_position <= min_position_down) //si minimo esta en la primera mitad 
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
				i = min_position_down;
				while(i > 0)
				{
					rra(head_a); 
					i--;
				}
			}
			pb(head_a, head_b);
			size_a --;
			substack ++;
		}
		max += 25;
	}	
	
	//ACA DEBERIA ORDENAR B
	size_b = ft_lstsize(*head_b);
	while(size_b > 0)
	{
		//max_position = find_max_position500(*head_b);
		max_position = find_max_position(*head_b);
		if (max_position <= (size_b/2 + 1)) //si maximo esta en la primera mitad
		{
			i = 1;
			while(i < max_position)
			{
				rb(head_b);
				i++;
			}
		}
		else //si maximo esta en la segunda mitad
		{
			i = ft_lstsize(*head_b);
			while(i >= max_position)
			{
				rrb(head_b); 
				i--;
			}
		}
		pa(head_a, head_b); 
		size_b--;
	}
}