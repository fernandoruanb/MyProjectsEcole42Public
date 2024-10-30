/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:29:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 10:34:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*char	*ft_strrchr(const char *s, int c);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 3)
		return (1);
	result = ft_strrchr(argv[1], argv[2][0]);
	result2 = strrchr(argv[1], argv[2][0]);
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[length]);
	while (length > 0)
	{
		if (s[length - 1] == (unsigned char)c)
			return ((char *)&s[length - 1]);
		length--;
	}
	return (NULL);
}
