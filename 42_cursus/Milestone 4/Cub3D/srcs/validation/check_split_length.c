/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:01:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 19:16:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_split_length(char **split)
{
	int	index;

	index = 0;
	while (split[index] != NULL)
		index++;
	if (index > 1)
		return (ft_putendl_fd_0("Too many texture spaces", 2));
	return (1);
}
