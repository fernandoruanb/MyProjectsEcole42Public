/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:55:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/19 15:25:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char **argv)
{
	int		index;
	char	**result;
	t_stack	stacks;

	index = 1;
	while (index < argc)
	{
		result = ft_split(argv[index]);
		if (!is_valid(result, &stacks))
			return (0);
		free(result);
		index++;
	}
	return (1);
}
