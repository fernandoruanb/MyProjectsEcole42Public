/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:00:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 19:00:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ordenation(char **str, char **next_str);

void	print_params(char *str);

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	count;
	int	index;

	count = 1;
	while (count < argc - 1)
	{
		index = 1;
		while (index < argc - count)
		{
			ordenation(&argv[index], &argv[index + 1]);
			index++;
		}
		count++;
	}
	count = 1;
	while (count < argc)
	{
		print_params(argv[count]);
		ft_putchar('\n');
		count++;
	}
	return (0);
}

void	ordenation(char **str, char **next_str)
{
	int		index;
	char	*temp;

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
		ft_putchar(str[index]);
		index++;
	}
}
