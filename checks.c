/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:32:14 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/15 18:30:13 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	errors(int argc, char **args, int i, long temp)
{
	if (!is_num(args[i]) || !duplicates(temp, args, i) || temp < INT_MIN
		|| temp > INT_MAX)
	{
		if (argc == 2)
			free_string(args);
		error("Error");
	}
}

void	ft_one_number(char **args)
{
	long	temp;

	if (!args[1])
	{
		free_string(args);
		exit (EXIT_SUCCESS);
	}
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
	ft_one_number(args);
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		errors(argc, args, i, temp);
		i++;
	}
	if (argc == 2)
		free_string(args);
	return (1);
}
