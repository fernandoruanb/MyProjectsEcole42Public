/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:39:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 16:39:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void);

/*int	main(void)
{
	ft_print_alphabet();
	ft_putchar('\n');
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
