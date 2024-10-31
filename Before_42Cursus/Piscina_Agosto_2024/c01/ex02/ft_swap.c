/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:44:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 11:44:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
//int	main(void)
//{
//	int	number1;
//	int	number2;
//
//	number1 = 22;
//	number2 = 44;
//
//	printf("Os números originais eram A %d e B %d: ", number1, number2);
//
//	ft_swap(&number1, &number2);
//
//	printf("Os números novos são A %d e B %d: ", number1, number2);
//	return (0);
//}
// Senhor avaliador, não esquecer de incluir a biblioteca <stdio.h>
