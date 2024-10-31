/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:07:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 17:07:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ft(int *nbr);

/*int	main(void)
{
	int	number;

	number = 102;
	printf("O número era: %i\n", number);
	ft_ft(&number);
	printf("O número ficou: %i\n", number);
	return (0);
}*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
