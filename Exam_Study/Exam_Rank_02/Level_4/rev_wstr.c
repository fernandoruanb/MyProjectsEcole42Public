/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:55:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/27 16:12:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	int	length;
	int	start;
	int	end;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	length = ft_strlen(argv[1]);
	while (length > 0)
	{
		while ((length > 0) && (argv[1][length - 1] == ' '
			|| argv[1][length - 1] == '\t'))
			length--;
		end = length - 1;
		while ((length > 0) && (argv[1][length - 1] != ' '
			&& argv[1][length - 1] != '\t'))
			length--;
		start = length;
		while (start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		if (length - 1 > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
