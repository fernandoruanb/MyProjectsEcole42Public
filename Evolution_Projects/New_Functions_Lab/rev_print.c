/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:56:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 14:09:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s);

char			*rev_print(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}

char	*rev_print(char *str)
{
	size_t	length;

	if (!str)
		return (NULL);
	length = ft_strlen(str);
	while (length--)
		write(1, &str[length], 1);
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
