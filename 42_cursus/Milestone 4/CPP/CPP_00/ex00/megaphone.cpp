/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:24:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 12:44:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	manage_message(char c)
{
	if (c >= 'a' && c <= 'z')
		std::cout << (char)(c - 32);
	else
		std::cout << c;
}

int	main(int argc, char **argv)
{
	int	index;
	int	count;

	index = 1;
	count = 0;
	if (argc > 1)
	{
		while (index < argc)
		{
			count = 0;
			while (argv[index][count] != '\0')
			{
				manage_message(argv[index][count]);
				count++;
			}
			std::cout << " ";
			index++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
