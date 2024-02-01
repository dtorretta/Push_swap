/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:39 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 19:23:33 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_100(t_list **head_a, t_list **head_b)
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
			min_position = find_position(*head_a, max);
			min_position_down = rev_find_position(*head_a, max);
			if (min_position <= min_position_down)
			{
				i = 1;
				while(i < min_position)
				{
					ra(head_a);
					i++;
				}
			}
			else
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
	//ORDENAR B
	size_b = ft_lstsize(*head_b);
	while(size_b > 0)
	{
		max_position = find_max_position(*head_b);
		if (max_position <= (size_b/2 + 1))
		{
			i = 1;
			while(i < max_position)
			{
				rb(head_b);
				i++;
			}
		}
		else
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
	long max = 160;

	size_a = ft_lstsize(*head_a);
	while(size_a > 0)
	{
		substack = 0;
		while(substack < max) //buscar numeros del 0 a 20 que son el grupo 1
		{
			min_position = find_position(*head_a, max);
			min_position_down = rev_find_position(*head_a, max); 
			if (min_position <= min_position_down)
			{
				i = 1;
				while(i < min_position)
				{
					ra(head_a);
					i++;
				}
			}
			else
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
		max += 160;
	}	
	//ORDENAR B
	size_b = ft_lstsize(*head_b);
	while(size_b > 0)
	{
		max_position = find_max_position(*head_b);
		if (max_position <= (size_b/2 + 1))
		{
			i = 1;
			while(i < max_position)
			{
				rb(head_b);
				i++;
			}
		}
		else
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
