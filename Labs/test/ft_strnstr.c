/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:43:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/03 10:20:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../42_cursus/Libft/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 4)
		return (1);
	result = ft_strnstr(argv[1], argv[2], ft_atoi(argv[3]));
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	detect;
	size_t	f_detect;

	detect = 0;
	if (little[detect] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[detect] != '\0' && detect < len)
	{
		f_detect = 0;
		if (big[detect] == little[f_detect])
		{
			while (big[detect + f_detect] == little[f_detect]
				&& (detect + f_detect) < len)
			{
				f_detect++;
				if (little[f_detect] == '\0')
					return ((char *)&big[detect]);
			}
		}
		detect++;
	}
	return (NULL);
}
