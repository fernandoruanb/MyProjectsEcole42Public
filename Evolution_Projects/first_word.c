/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:27:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/16 23:27:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	pass;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	pass = 0;
	while ((argv[1][index] == ' ' || argv[index] == '\t') &&
		(argv[1][index] != '\0'))
                index++;
	while ((argv[1][pass] >= 'a' && argv[1][pass] <= 'z')
		|| (argv[1][pass] >= 'A' && argv[1][pass] <= 'Z')
		|| (argv[1][pass] >= '0' && argv[2][pass] <= '9')
		|| (argv[1][pass] == ',') && (argv[1][pass] != '\0'))
		pass++;
	write(1, &argv[1][index], pass);
	write(1, "\n", 1);
}
