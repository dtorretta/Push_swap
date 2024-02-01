/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:32:14 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 17:36:34 by dtorrett         ###   ########.fr       */
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
				//min_position = count; //ver si me sirve
			}
			current = current->next;
			//count++; //ver si me sirve
		}
	}
	return (min);
	//tengo un pointer a la posicion minima y un int con el valor de la posicion minima
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
	*stack = NULL; //free(stack);
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
	char **args; //deberia tratar de reciclarlo
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
			ft_printf("Error\n");
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