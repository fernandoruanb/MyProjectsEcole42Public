/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:45:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/18 07:45:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2)
		return (1);
	result = ft_sqrt(atoi(argv[1]));
	printf("(MY FUNCTION) %i.\n", result);
	return (0);
}*/

int	ft_sqrt(int nb)
{
	int	attempt;

	attempt = 0;
	while (attempt * attempt <= nb)
	{
		if ((attempt * attempt) == nb)
			return (attempt);
		attempt++;
	}
	return (0);
}
