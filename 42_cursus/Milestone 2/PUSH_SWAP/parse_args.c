/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:10:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/19 20:10:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_number(char *str)
{
	int	index;

	index = 0;
	while ((str[index] && (str[index] == '-' 
		|| str[index] == '+')))
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	if (str[index - 1] == '-' || str[index - 1] == '+')
		return (0);
	return (1);
}

int	*parse_args(int argc, char **argv, int *size)
{
	int	index;
	int	value;

	if (argc < 2)
	{
		printf("How to use: ./push_swap [args...]\n");
		return (1);
	}
	while (index < argc)
	{
		value = 0;
		if (!is_number(argv[index]))
			return (0);
		if (!is_valid_number(argv[index]))
			return (0);
		if (!has_duplicates(argc, argv)
			return (0);
		index++;
	}
	return (0);
}
