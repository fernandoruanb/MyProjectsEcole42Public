/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:28:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 10:28:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

/*char	*ft_strtrim(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 4)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("(MY FUNCTION)", result);
	return (0);
}*/

char	*ft_strtrim(const char *s1, const char *s2)
{
	int	index;
	int	len_s1;
	char	*buffer;

	index = 0;
	buffer = (char *)malloc(len_s1 + 1);
	buffer[len_s1] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	while (s[length])
		length++;
	return (length);
}
