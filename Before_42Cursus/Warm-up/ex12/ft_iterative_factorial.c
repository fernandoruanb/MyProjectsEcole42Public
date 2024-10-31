/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:41:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_iterative_factorial(int nb);

/*int	main(void)
{
	int	number;
	int	result;

	number = 12;
	result = ft_iterative_factorial(number);
	printf("%i! = %i\n", number, result);
	return (0);
}*/

int	ft_iterative_factorial(int nb)
{
	int	count;
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	if (nb > 12)
		return (0);
	count = nb - 1;
	result = nb;
	while (count > 1)
	{
		result *= count;
		count--;
	}
	return (result);
}
