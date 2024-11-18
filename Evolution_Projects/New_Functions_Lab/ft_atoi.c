/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:19:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/18 12:30:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2)
		return (1);
	result = ft_atoi(argv[1]);
	printf("%d\n", result);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	index;
	int	signal;

	result = 0;
	index = 0;
	signal = 1;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		|| str[index] == '\r' || str[index] == '\f')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result *= 10;
		result += (str[index] - '0');
		index++;
	}
	return (signal * result);
}
