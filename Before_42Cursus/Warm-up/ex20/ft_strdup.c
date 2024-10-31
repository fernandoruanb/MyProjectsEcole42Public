/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:14:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 19:14:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

int		count_characters(char *str);

char	*ft_strdup(char *str);

/*int	main(int argc, char **argv)
{
	char	*str;
	char	*buffer;

	if (argc < 2)
	{
		printf("Insira pelo menos 2 argumentos.\n");
		return (0);
	}
	str = argv[1];
	buffer = ft_strdup(str);
	printf("A string é: %s\n", buffer);
	return (0);
}*/

char	*ft_strdup(char *str)
{
	int		index;
	int		length;
	char	*buffer;

	length = count_characters(str);
	buffer = (char *)malloc(length + 1);
	index = 0;
	while (str[index] != '\0')
	{
		buffer[index] = str[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

int	count_characters(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
