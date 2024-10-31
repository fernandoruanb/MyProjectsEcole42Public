/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:34:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:34:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

/*int	main(void)
{
	int	number1;
	int	number2;
	int	div;
	int	mod;

	number1 = 2;
	number2 = 2;
	ft_div_mod(number1, number2, &div, &mod);
	printf("A divisão e o resto de %i e %i são %d e %d\n", number1,
	number2, div, mod);
	return (0);
}*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
