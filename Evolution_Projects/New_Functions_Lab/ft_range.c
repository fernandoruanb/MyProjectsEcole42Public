/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/22 14:23:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end);

int	main(int argc, char **argv)
{
	int	*result;
	int	len;
	int	index;

	if (argc < 3)
		return (1);
	len = abs(atoi(argv[2]) - atoi(argv[1])) + 1;
	result = ft_range(atoi(argv[1]), atoi(argv[2]));
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

int	*ft_range(int start, int end)
{
	int	*result;
	int	len;
	int	index;

	len = abs((end - start)) + 1;
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (0);
	index = 0;
	while (index < len)
	{
		if (start < end)
		{
			result[index] = start;
			start++;
		}
		else
		{
			result[index] = start;
			start--;
		}
		index++;
	}
	return (result);
}
