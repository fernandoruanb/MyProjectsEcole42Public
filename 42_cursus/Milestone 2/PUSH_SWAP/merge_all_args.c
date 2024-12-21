/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:49:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/21 15:56:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	erase_result(char **result)
{
	int	index;

	index = 0;
	while (result[index] != NULL)
	{
		free(result[index]);
		index++;
	}
	free(result);
}

char	**merge_all_args(int argc, char **argv, int total_numbers)
{
	char	**all_args;
	int	index;
	char	**result;
	int	count;

	all_args = (char **)ft_calloc(total_numbers + 1, sizeof(char *));
	if (!all_args)
		return (ft_putendl_fd_n("Failed allocating all_args", 2));
	index = 1;
	count = 0;
	while (index < argc)
	{
		result = ft_split(argv[index]);
		if (!all_args)
			return (ft_putendl_fd_n("Failed allocating all_args", 2));
		while (all_args[s_index] != NULL)
			all_args[count++] = result[s_index++];
		erase_result(result);
		index++;
	}
	return (all_args);
}

int	main(int argc, char **argv)
{
	char	**result;
	int	count_numbers;
	int	index;

	count_numbers = count_all_numbers(argc, argv);
	printf("Total numbers: %d\n", count_numbers);
	result = merge_all_args(argc, argv, count_numbers);
	if (!result)
		return (ft_putendl_fd_1("Impossible to merge args.", 2));
	index = 0;
	while (result[index] != NULL)
	{
		printf("Array[%d]: %s\n", index, result[index]);
		index++;
	}
	free(result);
	return (0);
}
