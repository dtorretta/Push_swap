/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:28:49 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/12 16:28:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*searchs the whole list for the min value without index*/
t_list	*get_min(t_list **head)
{
	t_list	*current;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	current = *head;
	if (current)
	{
		while (current)
		{
			if ((current->index == -1) && (!has_min 
					|| current->value < min->value))
			{
				min = current;
				has_min = 1;
			}
			current = current->next;
		}
	}
	return (min);
}

/*asigned an index, starting from 0, to each node of the list.
It looks for the the min value one by one*/
void	index_stack(t_list **head)
{
	t_list	*current;
	int		index;

	index = 0;
	current = get_min(head);
	while (current)
	{
		current->index = index++;
		current = get_min(head); 
	}
}

/*First check if the arguments are a string. if so, use split
Second it creates a new node for each value an asigned to a linked list
Third calls the function index_stackt*/
void	init_stack(t_list **stack, int argc, char **argv)
{
	char	**args;
	t_list	*new;
	int		i;

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
	if (argc == 2) 
		free_string(args);
}
