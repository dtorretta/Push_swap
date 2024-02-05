/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 20:21:18 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	long	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		bigsort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;

	i = 0;
	if (!check(argc, argv, i))
		return (EXIT_FAILURE);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (EXIT_FAILURE);
	*stack_a = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
		exit (EXIT_SUCCESS);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
	{
		free_stack(stack_a); 
		exit (EXIT_FAILURE); //?
	}
	*stack_b = NULL;
	ft_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
