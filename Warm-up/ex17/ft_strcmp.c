/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:36:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/20 10:36:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2);

/*int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 2)
		return (1);
	result = ft_strcmp(argv[1]);
	result2 = strcmp(argv[2]);
	printf("(MY FUNCTION) %i.\n", result);
	printf("(ORIGINAL) %i.\n", result2);
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
