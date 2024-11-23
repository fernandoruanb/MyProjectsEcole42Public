/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:52:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 16:31:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_elements(void *data);

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

int	cmp(void *data1, void *data2);

t_list	*ft_lstnew(void *content);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*new_node2;

	head = ft_lstnew(argv[1]);
	new_node = ft_lstnew(argv[2]);
	new_node2 = ft_lstnew(argv[3]);
	head->next = new_node;
	new_node->next = new_node2;
	ft_list_remove_if(&head, "oi2", cmp);
	ft_list_foreach(head, print_elements);
	return (0);

}*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		current = *begin_list;
		ft_list_remove_if(&current->next, data_ref, cmp);
	}	
}

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int	cmp(void *data1, void *data2)
{
	return (strcmp((char *)data1, (char *)data2));
}

void	print_elements(void *data)
{
	printf("%s\n", (char *)data);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}*/
