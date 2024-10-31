/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:56:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/29 20:56:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	len;

	index = argc - 1;
	while (index >= 1)
	{
		len = 0;
		while (argv[index][len] != '\0')
		{
			write(1, &argv[index][len], 1);
			len++;
		}
		index--;
		write(1, "\n", 1);
	}
	return (0);
}
