/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:19:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 18:42:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

void	rev_wstr(const char *str);

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}

void	rev_wstr(const char *str)
{
	int	index;
	size_t	length;

	length = ft_strlen(str);
	index = 0;
	while (length > 0)
	{
		if (str[length - 1] != ' ' && str[length - 1] != '\t')
		{
			while (str[length - 1] != ' ' && str[length - 1] != '\t'
				&& length > 0)
			{
				index++;
				length--;
			}
			write(1, &str[length - 1], index);
		}
		else if ((str[length - 1] == ' ' || str[length - 1] == '\t')
				&& length > 0)
		{
			write(1, " ", 1);
			length--;
		}
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
