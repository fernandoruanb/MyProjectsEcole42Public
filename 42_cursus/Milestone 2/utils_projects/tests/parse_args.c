/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:06:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 16:10:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_too_many_signals(const char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '-' || str[index] == '+')
			flag++;
		if (str[index] == '+')
			return (ft_putstr_fd_1("You can't put + signal.\n", 2));
		if (flag > 1)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_isdigit(char character)
{
	if ((character >= '0' && character <= '9')
		|| (character == '-'))
		return (1);
	return (0);
}

static int	is_valid(const char *str)
{
	long	value;
	int		index;

	if (has_too_many_signals(str))
		return (ft_putstr_fd_0("There is/are too many signals.\n", 2));
	value = ft_atoi(str);
	if (value < INT_MIN || value > INT_MAX)
		return (ft_putstr_fd_0("The number exceeds the INT_MIN/MAX\n", 2));
	index = 0;
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (ft_putstr_fd_0("There is/are not numbers.\n", 2));
		index++;
	}
	return (1);
}

int	parse_args(int argc, char **argv)
{
	int		index;
	int		flag;
	char	**result;

	flag = 0;
	if (argc == 2)
	{
		result = ft_split(argv[1]);
		if (!result)
			return (ft_putstr_fd_0("Error spliting!\n", 2));
		index = 0;
		while (result[index] != NULL)
		{
			if (!is_valid(result[index]))
				flag = 1;
			free(result[index]);
			index++;
		}
		if (flag == 1)
			return (0);
		free(result);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	result = parse_args(argc, argv);
	printf("The result is: %d\n", result);
	return (0);
}
