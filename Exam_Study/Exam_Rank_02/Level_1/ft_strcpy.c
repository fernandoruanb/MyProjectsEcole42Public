/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:36:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 11:08:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int	main(int argc, char **argv)
{
	char	*result;
	char	dest[50];

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = ft_strcpy(dest, argv[1]);
	printf("%s\n", result);
	return (0);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
