/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:15:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 12:51:04 by fruan-ba         ###   ########.fr       */
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
	int	start;
	int	len;
	int	end;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	result = ft_rrange(start, end);
	len = ft_abs(end - start) + 1;
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
	int	len;
	int	*tab;
	int	index;

	len = ft_abs(end - start) + 1;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	index = 0;
	while (index < len)
	{
		if (start < end)
		{
			tab[index] = end;
			end--;
		}
		else
		{
			tab[index] = end;
			end++;
		}
		index++;
	}
	return (tab);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
