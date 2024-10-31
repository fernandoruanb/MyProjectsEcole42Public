/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:52:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 16:52:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void);

/*int	main(void)
{
	ft_print_numbers();
	ft_putchar('\n');
	return (0);
}*/

void	ft_print_numbers(void)
{
	int	number;

	number = 0;
	while (number < 10)
	{
		ft_putchar(number + '0');
		number++;
	}
}
