/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:50:39 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/15 18:36:53 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function only free stack A. is not necessary to free stack B as 
this function is always called before its creation*/
int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		else
		{
			temp = temp->next;
			if (!temp->next)
			{
				free_stack(stack);
				break ;
			}
		}
	}
	return (1);
}

/* file descriptor 2 is typically associated with the standard error output
(stderr) instead of standard output (stdout) 1*/
void	error(char *msg)
{
	(void)msg;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free (stack);
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}
