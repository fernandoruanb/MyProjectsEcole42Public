/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/14 15:01:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void);

/*int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}*/

void	ft_print_alphabet(void)
{
	char	first_letter;
	int		index;

	first_letter = 'a';
	index = 0;
	while (index < 26)
	{
		ft_putchar(first_letter);
		first_letter++;
		index++;
	}
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
