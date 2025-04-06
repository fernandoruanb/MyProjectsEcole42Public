/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:24:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/06 19:27:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	manage_message(char c, char next)
{
	if (c == '\\')
	{
		if (next == 'n') {std::cout << std::endl; return ;}
		if (next == 't') {std::cout << '\t'; return ;}
		if (next == 'b') {std::cout << '\b'; return ;}
		if (next == 'v') {std::cout << '\v'; return ;}
		if (next == 'f') {std::cout << '\f'; return ;}
		if (next == 'a') {std::cout << '\a'; return ;}
		if (next == 'r') {std::cout << '\r'; return ;}
		if (next == '\\') {std::cout << '\\'; return ;}
	}
	else if (c >= 'a' && c <= 'z')
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
				manage_message(argv[index][count], argv[index][count + 1]);
				if (argv[index][count] == '\\' && argv[index][count + 1] != '\0')
					count += 2;
				else
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
