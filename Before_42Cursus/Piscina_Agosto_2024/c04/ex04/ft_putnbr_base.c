/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:26:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/27 19:26:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include "../ex03/ft_atoi.c"*/

void	ft_putnbr_base(int nbr, char *base);

int		has_duplicates(char *base);

int		is_valid_base(char *base);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*number_char;
	int	number;
	char	*base;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	number_char = argv[1];
	base = argv[2];
	number = ft_atoi(number_char);
	ft_putnbr_base(number, base);

	//0123456789ABCDEF
	//poneyvif
	//01
	//0123456789
	return (0);
}
*/
int	is_valid_base(char *base)
{
	int	lenght;
	int	index;

	lenght = 0;
	index = 0;
	while (base[lenght] != '\0')
		lenght++;
	if (lenght < 2)
		return (0);
	if (has_duplicates(base))
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '-' || base[index] == '+')
			return (0);
		index++;
	}
	return (1);
}

int	has_duplicates(char *base)
{
	int	index;
	int	second_index;

	index = 0;
	second_index = 0;
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	index;
	int	second_index;

	index = 0;
	second_index = 0;
	while (base[index] != '\0')
		index++;
	if (is_valid_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			write(1, "-", 1);
		}
		if (nbr >= index)
		{
			ft_putnbr_base(nbr / index, base);
		}
		write(1, &base[nbr % index], 1);
	}
	else
		return ;
}
