/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-remove_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:25:35 by jonas             #+#    #+#             */
/*   Updated: 2025/03/06 10:27:06 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_nonquoteslen(char *str, char quote)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += str[i] != quote;
		i += 1 + (str[i] == '\\');
	}
	return (len);
}

static int	my_find_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_quote(str[i]))
			return (i);
	return (-1);
}

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*new;

	if (!str)
		return (NULL);
	i = 0;
	quote = str[my_find_quote(str)];
	j = 0;
	new = ft_calloc (get_nonquoteslen(str, quote) + 1, 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] != quote)
			new[j++] = str[i];
		i += 1 + (str[i] == '\\');
	}
	free(str);
	return (new);
}
