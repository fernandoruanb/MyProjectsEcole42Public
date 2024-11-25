/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:51:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 16:54:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n);

int	main(void)
{
	int	result;

	result = is_power_of_2(1);
	printf("%d\n", result);
	return (0);
}

int	is_power_of_2(unsigned int n)
{
	if ((n & 1) == 0)
		return (1);
	return (0);
}
