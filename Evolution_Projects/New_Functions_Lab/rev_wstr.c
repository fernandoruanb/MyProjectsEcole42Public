/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:35:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/24 08:59:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	length;

	length = ft_strlen(argv[1]);
	while (length > 0)
	{
		while ((length > 0) && (argv[1][length - 1] == ' '
			|| argv[1][length - 1] == '\t'))
			length--;
		end = length - 1;
		while ((length > 0) && argv[1][length - 1] != ' '
			&& argv[1][length - 1] != '\t')
			length--;
		start = length;
		while (start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}

static int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
