/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:47:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 11:54:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	ft_list_size(t_list *begin_list);

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*new_node2;
	int	result;

	head = ft_lstnew(argv[1]);
	new_node = ft_lstnew(argv[2]);
	new_node2 = ft_lstnew(argv[3]);
	head->next = new_node;
	new_node->next = new_node2;
	result = ft_list_size(head);
	printf("%d\n", result);
	return (0);
}

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}
