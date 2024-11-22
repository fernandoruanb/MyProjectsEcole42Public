/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:26:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/22 15:51:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_abs(int n);

int	*ft_rrange(int start, int end);

int	main(int argc, char **argv)
{
	int	index;
	int	*result;
	int	len;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	len = ft_abs(atoi(argv[1]) - atoi(argv[2])) + 1;
	result = ft_rrange(atoi(argv[1]), atoi(argv[2]));
	index = 0;
	while (index < len)
	{
		if (index < len - 1)
			printf("%d, ", result[index]);
		else
			printf("%d.\n", result[index]);
		index++;
	}
	return (0);
}

int	*ft_rrange(int start, int end)
{
	int	*result;
	int	len;
	int	index;

	len = ft_abs(end - start) + 1;
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (0);
	index = 0;
	while (index < len)
	{
		if (start < end)
		{
			result[index] = end;
			end--;
		}
		else
		{
			result[index] = end;
			end++;
		}
		index++;
	}
	return (result);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
