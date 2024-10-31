/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:44:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/29 08:44:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

/*int	main(void)
{
	int	number;
	int	next_prime_number;

	number = 13;
	next_prime_number = ft_find_next_prime(number);
	printf("O número pode ser o próximo ou igual\n.");
	printf("O próximo número primo após %i é: %i\n", number, next_prime_number);
	return (0);
}
//Caro avaliador, não esquecer da <stdio.h>
*/
int	ft_find_next_prime(int nb)
{
	int	attempt;

	while (1)
	{
		attempt = 2;
		while (attempt * attempt <= nb)
		{
			if (nb % attempt == 0)
				break ;
			attempt++;
		}
		if (attempt * attempt > nb)
			return (nb);
		nb++;
	}
}
