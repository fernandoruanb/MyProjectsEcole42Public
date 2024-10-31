/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:49:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:49:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_recursive_factorial(int nb);

/*int	main(void)
{
	int	number;
	int	result;

	number = 400;
	result = ft_recursive_factorial(number);
	printf("%i! = %i.\n", number, result);
	return (0);
}*/

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else if (nb > 12)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
