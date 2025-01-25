/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:05:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 18:50:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	clean_all_pipes(int argc, int pipefds[][2])
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		close_descriptors(pipefds[index], NULL);
		index++;
	}
	return (1);
}
