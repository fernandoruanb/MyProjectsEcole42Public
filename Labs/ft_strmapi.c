/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:59:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 10:11:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

static char	ft_toupper_i(unsigned int index, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 2)
		return (1);
	result = ft_strmapi(argv[1], &ft_toupper_i);
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	int	len_s;
	int	index;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	buffer = (char *)malloc(len_s + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		buffer[index] = f(index, s[index]);
		index++;
	}
	return (buffer);
}

static char	ft_toupper_i(unsigned int index, char c)
{
	if (index % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - ('a' - 'A'));
	return (c);
}
