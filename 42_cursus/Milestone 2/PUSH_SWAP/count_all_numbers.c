/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_all_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:24:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/21 13:46:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		result = ft_split(argv[index]);
		if (!result)
			return (ft_putendl_fd_0("Mistake splitting.", 2));
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
