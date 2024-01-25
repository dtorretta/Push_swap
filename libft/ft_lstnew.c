/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:18 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/24 15:33:08 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	*str = "Hello";
	t_list	*elem = ft_lstnew(str);
	
	printf("new content: %s\n", (char *)elem->content);
	free(elem);
}*/
/*This function allocates memory for a new element of type t_list. 
It sets the next variable to NULL.*/
