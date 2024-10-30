/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 10:27:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*char	*ft_strchr(const char *s, int c);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 3)
		return (1);
	result = ft_strchr(argv[1], argv[2][0]);
	result2 = strchr(argv[1], argv[2][0]);
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

char	*ft_strchr(const char *s, int c)
{
	int	index;
	int	len_s;

	index = 0;
	len_s = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len_s]);
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
