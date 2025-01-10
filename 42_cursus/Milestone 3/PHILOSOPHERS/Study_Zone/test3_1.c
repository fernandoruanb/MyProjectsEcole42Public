/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:48:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	mails = 0;

int	main(void)
{
	int	index;

	index = 0;
	while (index < INT_MAX)
	{
		index++;
		mails++;
	}
	printf("Target mail: %d\n", mails);
	return (0);
}
