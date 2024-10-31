/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:48:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 11:48:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
//int	main(void)
//{
//	int	a;
//	int	b;
//	int	div;
//	int	mod;
//
//	a = 100;
//	b = 2;
//
//	ft_div_mod(a, b, &div, &mod);
//
//	printf("O resultado da divisão de %d por %d é: %d\n", a, b, div);
//	printf("O resto da divisão entre %d por %d é: %d\n", a, b, mod);
//	return (0);
//}
//Caro avaliador, não esqueça de por a biblioteca <stdio.h>
