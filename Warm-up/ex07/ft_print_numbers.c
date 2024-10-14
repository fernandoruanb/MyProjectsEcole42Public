/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/14 15:15:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_putchar(char c);

/*void	ft_print_numbers(void);

int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}*/

void	ft_print_numbers(void)
{
	char	number;
	int		index;

	number = '0';
	index = 0;
	while (index < 10)
	{
		ft_putchar(number);
		number++;
		index++;
	}
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
