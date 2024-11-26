/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:48:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 19:02:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	index;
	int	result;
	int	number;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 1;
	number = ft_atoi(argv[1]);
	while (index < 11)
	{
		result = number * index;
		ft_putnbr(index);
		write(1, " x ", 3);
		ft_putnbr(number);
		write(1, " = ", 3);
		ft_putnbr(result);
		index++;
	}
	return (0);
}
