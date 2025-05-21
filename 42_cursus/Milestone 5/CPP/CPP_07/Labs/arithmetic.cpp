/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:37:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 11:44:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.hpp"

int	main(void)
{
	auto result = add(2, 3);
	auto result2 = sub(2, 3);
	auto result3 = mul(2, 2);
	auto result4 = my_div(10, 0);
	auto result5 = mod(10, 3);

	std::cout << "Result: " << result << std::endl;
	std::cout << "Result2: " << result2 << std::endl;
	std::cout << "Result3: " << result3 << std::endl;
	std::cout << "Result4: " << result4 << std::endl;
	std::cout << "Result5: " << result5 << std::endl;
	return (0);
}
