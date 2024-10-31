/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:11:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/21 19:11:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>*/

int	ft_strncmp(char *s1, char *s2, unsigned int n);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	unsigned int	limiter = 3;
	int	result;
	int	result2;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	result = ft_strncmp(s1, s2, limiter);
	printf("O resultado foi: %i\n", result);
	result2 = strncmp(s1, s2, limiter);
	printf("O resultado da original foi: %i\n", result2);
	return (0);
}
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && s1[index] != '\0'
		&& s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	if (index < n)
		return (s1[index] - s2[index]);
	return (0);
}
