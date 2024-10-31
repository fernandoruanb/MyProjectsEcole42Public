/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:54:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 11:54:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;
	int	temp2;

	if (*b == 0)
		return ;
	temp = *a / *b;
	temp2 = *a % *b;
	*a = temp;
	*b = temp2;
}
//int	main(void)
//{
//	int a;
//	int b;
//
//	a = 10;
//	b = 5;
//
//	printf("Os números de A %d e B %d agora se tornaram resultados.\n", a, b);
//	ft_ultimate_div_mod(&a, &b);
//	printf("Agora temos o resultado da divisão %d e resto %d.\n", a, b);
//	return (0);
//}
// Caro avaliador, não esqueça da <stdio.h>
