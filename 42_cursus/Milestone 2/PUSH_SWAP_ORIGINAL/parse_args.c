/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:04:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 14:22:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	has_duplicate(int argc, char **argv, t_struct *stack)
{
	int	index;
	int	s_index;

	index = 1;
	while (index < argc)
	{
		s_index = index + 1;
		while (s_index < argc - 1)
		{
			if (ft_strcmp(argv[index], argv[s_index]) == 0)
				return (0);
			s_index++;
		}
		index++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_struct *stack)
{
	int	index;
	int	s_index;

	index = 0;
	while ()
}
