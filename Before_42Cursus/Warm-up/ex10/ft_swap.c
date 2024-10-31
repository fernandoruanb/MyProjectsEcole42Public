/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:15:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:15:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b);

/*int	main(void)
{
	int	number1;
	int	number2;

	number1 = 2;
	number2 = 4;
	printf("Os números eram %i e %i\n", number1, number2);
	ft_swap(&number1, &number2);
	printf("Os números trocados ficaram %i e %i\n", number1, number2);
	return (0);
}*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
