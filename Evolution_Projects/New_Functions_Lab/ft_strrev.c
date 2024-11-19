/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:56:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/18 20:56:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(const char *s);

/*char	*ft_strrev(char *str);

int	main(void)
{
	char	*result;
	char	str[8] = "Fernando";

	printf("A string bonita para teste: %s\n", str);
	result = ft_strrev(str);
	printf("O resultado ficou: %s\n", result);
	return (0);
}*/

char	*ft_strrev(char *str)
{
	char	temp;
	size_t	index;
	size_t	length;

	index = 0;
	length = ft_strlen(str);
	while (index < length)
	{
		temp = str[index];
		str[index] = str[length - 1];
		str[length - 1] = temp;
		index++;
		length--;
	}
	return (str);
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
