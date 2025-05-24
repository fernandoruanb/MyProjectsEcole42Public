/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:20:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 18:01:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	int	index;

	Array<std::string> countries(4);
	Array<int> a;
	Array<int> b(5);
	Array<int> c;

	std::cout << std::endl;
	try
	{
		std::cout << MAGENTA "============= TEST 1 - EMPTY ARRAY =================" RESET << std::endl;
		std::cout << a << std::endl;
		//a[0] = 1;
		std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "TEST 1 ERROR FOUND!!!" RESET << std::endl;
	}
	try
	{
		std::cout << MAGENTA "=============== TEST 2 - INT ARRAY =================" RESET << std::endl;
		index = 0;
		while (index < 5)
		{
			b[index] = index * 10;
			std::cout << "b[" << index << "] = " << b[index] << std::endl;
			index++;
		}
		c = b;
		std::cout << MAGENTA "============ TEST 2.1 - INVALID ACCESS ===============" RESET << std::endl;
		//std::cout << b[100] << std::endl;
		std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "TEST 2 ERROR FOUND!!!" RESET << std::endl;
	}
	try
	{
		std::cout << MAGENTA "=============== TEST 3 - CRAZY LENGTH =================" RESET << std::endl;
		Array<int> d(1000000000);
		std::cout << "Allocation success!!!" << std::endl;
		std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "TEST 3: ERROR FOUND!!! CRAZY ALOCATION OF MEMORY" << std::endl;
	}
	try
	{
		std::cout << MAGENTA "============ TEST 4 - COPY ACCESS ===============" RESET << std::endl;
		index = 0;
                while (index < 5)
                {
                        std::cout << "c[" << index << "] = " << c[index] << std::endl;
                        index++;
                }
		std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "TEST 4 FAILED!!! COPY ACCESS FAILED!!!" RESET << std::endl;
	}
	try
	{
		std::cout << MAGENTA "============ TEST 5 COPY CONSTRUCTOR ACCESS ===============" RESET << std::endl;
		Array<int> e(c);
		index = 0;
		while ((unsigned int)index < e.size())
		{
			std::cout << "E[" << index << "]: " << e[index] << std::endl;
			index++;
		}
		std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "TEST 5 FAILED!!!" RESET << std::endl;
	}
	try
	{
		std::cout << MAGENTA "============ TEST 6 STD::STRING ===============" RESET << std::endl;
		{
			index = 0;
			countries[0] = "Brazil";
			countries[1] = "United States";
			countries[2] = "Singapore";
			countries[3] = "Malta";
			//countries[4] = "Another";
			while ((unsigned int)index < countries.size())
			{
				std::cout << YELLOW << countries[index] << RESET << std::endl;
				index++;
			}
		}
	}
	catch(std::exception &e)
	{
		std::cerr << RED "FAILED TEST 6!!!" RESET << std::endl;
	}
	std::cout << MAGENTA "====================================================" RESET << std::endl << std::endl;
	return (0);
}
