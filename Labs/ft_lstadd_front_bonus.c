/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:38:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 09:47:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*new_node2;
	t_list	*new_node3;

	if (argc < 3)
		return (1);
	head = ft_lstnew(argv[1]);
	new_node = ft_lstnew(argv[2]);
	new_node2 = ft_lstnew(argv[3]);
	new_node3 = ft_lstnew(argv[4]);
	head->next = new_node;
	new_node->next = new_node2;
	new_node2->next = new_node3;
	ft_lstadd_front(&head, new_node3);
	printf("O conteúdo da frente agora é: %s.\n", (char *)head->content);
	return (0);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
