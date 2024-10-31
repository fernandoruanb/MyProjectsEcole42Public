/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:46:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/29 20:46:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	len;

	index = 1;
	while (index < argc)
	{
		len = 0;
		while (argv[index][len] != '\0')
		{
			write(1, &argv[index][len], 1);
			len++;
		}
		index++;
		write(1, "\n", 1);
	}
	return (0);
}
