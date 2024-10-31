/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:19:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 18:19:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_strlen(char *str);

/*int	main(void)
{
	char	*str;
	int	result;

	str = "Hello, World!";
	result = ft_strlen(str);
	printf("A quantidade de caracteres em '%s' é: %i.\n", str, result);
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
