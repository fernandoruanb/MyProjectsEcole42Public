/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:18:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 17:43:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s);

void			ulstr(char *str);

int	main(int argc, char **argv)
{
	size_t	index;
	size_t	length;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	length = ft_strlen(argv[1]);
	ulstr(argv[1]);
	write(1, argv[1], length);
	write(1, "\n", 1);
	return (0);
}

void	ulstr(char *str)
{
	size_t	index;
	size_t	length;
	char	temp;

	index = 0;
	length = ft_strlen(str);
	while (str[index] != '\0')
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;
		else if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] += 32;
		index++;
	}
	index = 0;
	while (length > 0)
	{
		temp = str[index];
		str[index] = str[length - 1];
		str[length - 1] = temp;
		index++;
		length--;
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
