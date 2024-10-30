/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:42:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 08:45:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 2)
		return (1);
	result = ft_isdigit(argv[1][0]);
	result2 = isdigit(argv[1][0]);
	printf("(MY FUNCTION) %d.\n", result);
	printf("(ORIGINAL) %d.\n", result2);
	return (0);
}*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (1);
}
