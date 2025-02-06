/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/06 12:29:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	num;

	scanf("%d", &num);
	if (num < 0)
		printf("O número é negativo\n");
	else if (num == 0)
		printf("O número é zero.\n");
	else
		printf("O número é positivo.\n");
	return (0);
}
