/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:28:49 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 19:38:55 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_min(t_list **head)
{
	t_list	*current;
	t_list	*min;
	int		has_min; //???
	
	min = NULL; //todavia no apunta a nada
	has_min = 0; //??
	current = *head;

	if (current) //??
	{
		while (current)
		{
			if ((current->index == -1) && (!has_min || current->value < min->value))
			{
				min = current;
				has_min = 1;
			}
			current = current->next;
		}
	}
	return (min);
}
void	index_stack(t_list **head)
{
	t_list	*current;
	int		index;

	index = 0;
	current = get_min(head);
	while (current) // mientras que desde current en adelante hayan nodos
	{
		current->index = index++;
		current = get_min(head); //busca el siguiente minimo sin index.
	}
}
void	init_stack(t_list **stack, int argc, char **argv)
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
	index_stack(stack);
	if (argc == 2) //si arc = 2 entonces usamos split. split usa malloc y tengo que liberar la memoria. ya no me sirve args porque cree el stack
	{
		free_string(args);
	}
}
