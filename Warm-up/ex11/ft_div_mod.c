/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:52:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/16 15:52:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(int argc, char **argv)
{
	int	div;
	int	mod;

	if (argc < 2)
		return (1);
	printf("Os números para teste: %i e %i.\n", atoi(argv[1]), atoi(argv[2]));
	ft_div_mod(atoi(argv[1]), atoi(argv[2]), &div, &mod);
	printf("(MY FUNCTION) divisão: %i | resto: %i.\n", div, mod);
	return (0);
}*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
