/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:56:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/05 10:56:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int		ft_strlen(char *src);

char	*ft_strdup(char *src);

/*int	main(void)
{
	char	*src;
	char	*result;

	src = "Hello, World!";
	result = ft_strdup(src);
	printf("O resultado ficou: %s\n", result);
	return (0);
}
*/
char	*ft_strdup(char *src)
{
	int		total_length;
	char	*buffer;
	int		index;

	index = 0;
	total_length = ft_strlen(src);
	buffer = (char *)malloc(total_length);
	while (src[index] != '\0')
	{
		buffer[index] = src[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

int	ft_strlen(char *src)
{
	int	length;

	length = 0;
	while (src[length] != '\0')
		length++;
	return (length + 1);
}
