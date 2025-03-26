/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_insider_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:24:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/10 13:26:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_insider_quotes(t_token *root, t_utils *data)
{
	size_t	length;

	check_copy_new(data);
	if (!data->paths)
		return (1);
	if (!root)
		return (0);
	length = ft_strlen(root->str);
	if ((root->str[0] == '\'' && root->str[length - 1] == '\'')
		|| (root->str[0] == '\"' && root->str[length - 1] == '\"'))
	{
		data->new_str = ft_substr(root->str, 1, length - 2);
		if (!data->new_str)
			return (0);
		data->copy_new = ft_strdup(data->new_str);
		if (!data->copy_new)
			return (1);
		if (test_all_paths(data))
			return (1);
	}
	return (0);
}
