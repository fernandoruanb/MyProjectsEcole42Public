/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:28:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 15:37:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

/*size_t	ft_strlen(const char *s);

char	*ft_strrev(char *str);

int	main(int argc, char **argv)
{
	char	*result;
	char	str[7] = "banana";

	result = ft_strrev(str);
	printf("%s\n", result);
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

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
