/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:06:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/05 15:06:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	has_duplicates(char *base);

int	is_valid_base(char *base);

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	ft_putnbr_base(1200, "01");
	write(1, "\n", 1);
	ft_putnbr_base(1200, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(1200, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(1200, "0123456789");
	write(1, "\n", 1);
	return (0);
}
void	ft_putnbr_base(int nbr, char *base)
{
	int	certificate;
	int	length;

	certificate = is_valid_base(base);
	if (certificate == 0)
		return ;
	length = 0;
	while (base[length] != '\0')
		length++;
	if (nbr >= length)
		ft_putnbr_base(nbr / length, base);
	write(1, &base[nbr % length], 1);
}

int	has_duplicates(char *base)
{
	int	index;
	int	second_index;

	index = 0;
	while (base[index] != '\0')
	{
		second_index = index + 1;
		while (base[second_index] != '\0')
		{
			if (base[index] == base[second_index])
				return (1);
			second_index++;
		}
		index++;
	}
	return (0);
}

int	is_valid_base(char *base)
{
	int	length;

	length = 0;
	while (base[length] != '\0')
	{
		if (base[length] == '+' || base[length] == '-')
			return (0);
		length++;
	}
	if (length < 2)
		return (0);
	if (has_duplicates(base))
		return (0);
	return (1);
}
