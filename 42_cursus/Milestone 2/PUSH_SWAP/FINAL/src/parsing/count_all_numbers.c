/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_all_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:24:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:00:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_all_numbers(int argc, char **argv)
{
	int		index;
	int		s_index;
	int		count;
	char	**result;

	index = 1;
	s_index = 0;
	count = 0;
	while (index < argc)
	{
		result = ft_split(argv[index], ' ');
		if (!result)
			return (0);
		s_index = 0;
		while (result[s_index] != NULL)
		{
			free(result[s_index]);
			s_index++;
			count++;
		}
		free(result);
		index++;
	}
	return (count);
}

/*int	main(int argc, char **argv)
{
	int	result;

	result = count_all_numbers(argc, argv);
	printf("The amount of numbers are: %d\n", result);
	return (0);
}*/
