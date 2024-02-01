/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:32:14 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 19:51:47 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list **stack)
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
static int	is_num(char *num)
{
	int i;

	i = 0;
	if ((num[i] == '+' || num[i] == '-') && !ft_isdigit(num[1])) // check que solo haya un signo #
		return(0);
	if (num[i] == '+' || num[i] == '-')
		i++;
	while(num[i])
	{
		while(num[i] == ' ')
			i++;
		if(!ft_isdigit(num[i]))
			return(0);
		else
			i++;
	} 
	return (1);
}
static int duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (num != atoi(argv[i]))
			i++;
		else
			return(0);
	}
	return (1);
}
int check(int argc, char **argv, int i)
{
	char **args;
	long temp; //puedo eliminarlo?

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
	while(args[i])
	{
		temp = ft_atoi(args[i]); //tengo que usar atoi igual prque luego de split todo queda como string
		if (!is_num(args[i]) || !duplicates(temp, args, i) || temp < INT_MIN || temp > INT_MAX)
		{
			ft_printf("Error\n"); //ver con leo
			return(0);
		}
		i++;
	}
	if (argc == 2)
		free_string(args);
	return(1);
}

// int main (int argc, char **argv)
// {
// 	if (!check(argc, argv))
// 		ft_printf("Error\n");
// 	else
// 		ft_printf("Good\n");
// 	return(0);
// }