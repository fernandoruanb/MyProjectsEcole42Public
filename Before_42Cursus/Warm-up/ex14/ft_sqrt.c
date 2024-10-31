/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:56:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_sqrt(int nb);

/*int	main(void)
{
	int	number;
	int	result;

	number = 16;
	result = ft_sqrt(number);
	printf("A raíz quadrada de %i é: %i\n", number, result);
	return (0);
}*/

int	ft_sqrt(int nb)
{
	int	attempt;

	attempt = 1;
	while (attempt * attempt <= nb)
	{
		if ((attempt * attempt) == nb)
			return (attempt);
		attempt++;
	}
	return (0);
}
