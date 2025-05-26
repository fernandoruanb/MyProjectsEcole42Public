/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:42:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 17:46:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

int	main(void)
{
	LabClass<int> star;

	star.push(42);
	std::cout << star.top() << std::endl;
	star.push(84);
	std::cout << star.top() << std::endl;
	return (0);
}
