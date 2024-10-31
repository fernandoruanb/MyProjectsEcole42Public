/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:16:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/30 19:16:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ordenation(char **str, char **next_str);

void	print_params(char *str);

int	main(int argc, char **argv)
{
	int	count;
	int	second_index;

	count = 1;
	if (argc < 2)
		return (0);
	while (count < argc - 1)
	{
		second_index = 1;
		while (second_index < argc - count)
		{
			ordenation(&argv[second_index], &argv[second_index + 1]);
			second_index++;
		}
		count++;
	}
	count = 1;
	while (count < argc)
	{
		print_params(argv[count]);
		count++;
	}
	return (0);
}

void	ordenation(char **str, char **next_str)
{
	char	*temp;
	int		index;

	index = 0;
	while ((*str)[index] == (*next_str)[index])
		index++;
	if ((*str)[index] > (*next_str)[index])
	{
		temp = *str;
		*str = *next_str;
		*next_str = temp;
	}
}

void	print_params(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
	write(1, "\n", 1);
}
