/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:45:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/21 17:29:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(const char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

void	epur_str(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0 && str[index] == ' ')
			index++;
		if (str[index] == ' ' && str[index + 1] != ' ')
			write(1, &str[index], 1);
		else if (str[index] != ' ')
			write(1, &str[index], 1);
		index++;
	}
}
