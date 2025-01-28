/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:06:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 10:12:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_data	add_token(char *token, char **split_tokens)
{
	t_data	*add_token;

	add_token = malloc(sizeof(t_data));
	if (!add_token)
		return (NULL);
	add_token->data = token;
	add_token->type = what_is_my_type(token, split_tokens);
	add_token->next_token = 
	return (add_token);
}
