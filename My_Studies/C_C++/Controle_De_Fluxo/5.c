/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/06 16:02:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	num;

	scanf("%d", &num);
	if (num % 2 == 0)
		printf("O número é par\n");
	else
		printf("O número é ímpar\n");
	return (0);
}
