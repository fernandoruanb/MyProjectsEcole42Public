/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:57:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/07 13:57:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tokens(t_token *root)
{
	t_token	*temp;

	while (root)
	{
		temp = root->next;
		root->next = NULL;
		root->previous = NULL;
		free(root);
		root = temp;
	}
	root = NULL;
}
