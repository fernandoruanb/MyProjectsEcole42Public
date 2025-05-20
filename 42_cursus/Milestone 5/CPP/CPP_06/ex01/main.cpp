/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:52:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/20 10:19:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	t_data	test;
	uintptr_t	ptr;
	t_data*	recover;

	test.id = 1;
	test.name = "test";
	test.c = 'a';
	test.number = 20.022f;
	test.test_double = 20.022;

	std::cout << "The pointer is: " << &test << std::endl;
	std::cout << "The test name is: " << test.name << std::endl;
	std::cout << "The id test is: " << test.id << std::endl;
	std::cout << "The secret char is: " << test.c << std::endl;
	std::cout << "The float number is: " << test.number << std::endl;
	std::cout << "The double number is: " << test.test_double << std::endl;

	ptr = Serializer::serialize(&test);
	std::cout << "The serialized ptr is: " << ptr << std::endl;
	recover = Serializer::deserialize(ptr);

	std::cout << "The new pointer is: " << recover << std::endl;
	std::cout << "The new name is: " << recover->name << std::endl;
	std::cout << "The new id is: " << recover->id << std::endl;
	std::cout << "The new caracter is: " << recover->c << std::endl;
	std::cout << "The new float number: " << recover->number << std::endl;
	std::cout << "The new double number: " << recover->test_double << std::endl;

	if (test.name == recover->name)
		std::cout << "The name is the same" << std::endl;
	else
		std::cerr << "The name isn't the same" << std::endl;
	if (test.id == recover->id)
		std::cout << "The id is the same" << std::endl;
	else
		std::cerr << "The id isn't the same" << std::endl;
	if (test.c == recover->c)
		std::cout << "The caracter is the same" << std::endl;
	else
		std::cerr << "The caracter isn't the same" << std::endl;
	if (test.number == recover->number)
		std::cout << "The float number is the same" << std::endl;
	else
		std::cerr << "The float number isn't the same" << std::endl;
	if (test.test_double == recover->test_double)
		std::cout << "The test_double is the same" << std::endl;
	else
		std::cerr << "The test_double isn't the same" << std::endl;
	return (0);
}
