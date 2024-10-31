/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:19:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/28 15:19:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

/*int	main(void)
{
	int	result;
	int	number;

	number = 5;
	result = ft_recursive_factorial(number);
	printf("O resultado do fatorial de %i é: %i\n", number, result);
	return (0);
}
Caro avaliador, não se esquecer da <stdio.h>
*/
int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
