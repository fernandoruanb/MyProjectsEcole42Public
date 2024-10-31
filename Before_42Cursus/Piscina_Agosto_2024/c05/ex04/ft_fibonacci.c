/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:13:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/28 21:13:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index);

/*int	main(void)
{
	int	index;
	int	result;

	index = 10;
	result = ft_fibonacci(index);
	printf("O resultado da fibonacci no index pedido é: %i\n", result);
	return (0);
}
Caro avaliador, não esquecer da <stdio.h>
*/
int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index < 0)
		return (-1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
