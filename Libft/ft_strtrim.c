/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:43:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 19:43:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int		calc_fi(char const *s1, char const *s2);

int		calculate_ini(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

/*char	*ft_strtrim(char const *s1, char const *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 3)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("(MY FUNCTION) %s.\n", result);
	free(result);
	return (0);
}*/

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		index;
	int		init;
	int		final;
	char	*buffer;

	init = calculate_ini(s1, s2);
	final = calc_fi(s1, s2);
	if (s1[0] == '\0' || init > final)
	{
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
		return (buffer);
	}
	index = 0;
	buffer = (char *)malloc((final - init) + 1);
	while (init <= final)
	{
		buffer[index] = s1[init];
		index++;
		init++;
	}
	buffer[index] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	calculate_ini(char const *s1, char const *s2)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s1[index] != '\0')
	{
		count = 0;
		while ((s1[index] != s2[count])
			&& s2[count] != '\0')
			count++;
		if (s2[count] == '\0')
			break ;
		index++;
	}
	return (index);
}

int	calc_fi(char const *s1, char const *s2)
{
	int	length;
	int	length_2;

	length = ft_strlen(s1) - 1;
	length_2 = ft_strlen(s2) - 1;
	while (length >= 0 && length_2 >= 0)
	{
		length_2 = ft_strlen(s2) - 1;
		while (s1[length] != s2[length_2]
			&& length_2 >= 0)
			length_2--;
		if (s2[length_2] == '\0')
			return (length);
		while (s1[length] == s2[length_2])
			length--;
	}
	return (length);
}
