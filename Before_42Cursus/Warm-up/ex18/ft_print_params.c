/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:37:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 18:37:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	index;
	int	second_index;

	index = 1;
	while (index < argc)
	{
		second_index = 0;
		while (argv[index][second_index] != '\0')
		{
			ft_putchar(argv[index][second_index]);
			second_index++;
		}
		ft_putchar('\n');
		index++;
	}
	return (0);
}
