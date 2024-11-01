/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:54:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 09:09:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

int	main(int argc, char **argv)
{
	t_list		*head;
	t_list		*new_node;
	t_list		*new_node2;
	t_list		*new_node3;

	if (argc < 5)
		return (1);
	head = 	ft_lstnew(argv[1]);
	new_node = ft_lstnew(argv[2]);
	new_node2 = ft_lstnew(argv[3]);
	new_node3 = ft_lstnew(argv[4]);
	head->next = new_node;
	new_node->next = new_node2;
	new_node2->next = new_node3;
	ft_lstclear(&head, NULL);
	if (!head)
		printf("A lista foi apagada com sucesso absoluto!\n");
	else
		printf("A lista ainda existe poxa!\n");
	return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*add_next;

	if (lst)
	{
		temp = *lst;
		while (temp)
		{
			add_next = temp->next;
			ft_lstdelone(temp, del);
			temp = add_next;
		}
		*lst = NULL;
	}
}
