/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:32:14 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/05 20:19:43 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				free_stack(stack); //*deberia liberar stack b?
				break ;
			}
		}
	}
	return (1);
}

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '+' || num[i] == '-') && !ft_isdigit(num[1]))
		return (0);
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i])
	{
		while (num[i] == ' ')
			i++;
		if (!ft_isdigit(num[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

static int	duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (num != atoi(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check(int argc, char **argv, int i)
{
	char	**args;
	long	temp;

	i = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!is_num(args[i]) || !duplicates(temp, args, i) || temp < INT_MIN
			|| temp > INT_MAX)
			error("Error"); //no deberia liberar la memoria de los stack antes de esto?
		i++;
	}
	if (argc == 2)
		free_string(args);
	return (1);
}
