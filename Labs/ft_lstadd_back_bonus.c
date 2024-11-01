/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:36:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 08:43:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_cursus/Libft/libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new);

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*new_node2;
	t_list	*new_node3;
	t_list	*result;

	if (argc < 5)
		return (1);
	head = ft_lstnew(argv[1]);
	new_node = ft_lstnew(argv[2]);
	new_node2 = ft_lstnew(argv[3]);
	new_node3 = ft_lstnew(argv[4]);
	head->next = new_node;
	new_node->next = new_node2;
	ft_lstadd_back(&head, new_node3);
	result = ft_lstlast(head);
	printf("O último nó é: %s.\n", (char *)result->content);
	return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
