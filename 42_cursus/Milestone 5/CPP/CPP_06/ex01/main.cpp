/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:52:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/18 17:53:25 by fruan-ba         ###   ########.fr       */
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
	
	std::cout << "The pointer is: " << &test << std::endl;
	std::cout << "The test name is: " << test.name;
	std::cout << "The id test is: " << test.id;

	ptr = Serializer::serialize(&test);
	recover = Serializer::deserialize(ptr);

	std::cout << "The new pointer is: " << recover << std::endl;
	std::cout << "The new name is: " << recover->name << std::endl;
	std::cout << "The new id is: " << recover->id << std::endl;
	if (test.name == recover->name)
		std::cout << "The name is the same" << std::endl;
	else
		std::cerr << "The name isn't the same" << std::endl;
	if (test.id == recover->id)
		std::cout << "The id is the same" << std::endl;
	else
		std::cout << "The id isn't the same" << std::endl;
	return (0);
}
