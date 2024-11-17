/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:59:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 11:06:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Next_Generation_Libft/libft.h"

void	ft_swap(int *a, int *b);

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	ft_printf("Os números eram: %d e %d\n", a, b);
	ft_swap(&a, &b);
	ft_printf("O resultado ficou: %d e %d\n", a, b);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
