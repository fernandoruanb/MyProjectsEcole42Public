/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:26:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/03 20:26:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>

void	contador(void)
{
	static int	chamadas = 0;

	chamadas++;
	printf("A função foi chamada %d vezes.\n", chamadas);
}

int	main(void)
{
	contador();
	contador();
	return (0);
}
