/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:25:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 18:25:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>
#include <string.h>*/

int	ft_strcmp(char *s1, char *s2);

/*int	main(void)
{
	char	*s1;
	char	*s2;
	int	result;
	int	result2;

	s1 = "abc";
	s2 = "ç";
	result = ft_strcmp(s1, s2);
	printf("O resultado foi: %i.\n", result);
	result2 = strcmp(s1, s2);
	printf("O resultado original foi: %i.\n", result2);
	return (0);
}*/

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
