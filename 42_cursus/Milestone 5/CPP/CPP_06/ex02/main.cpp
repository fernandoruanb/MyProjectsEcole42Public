/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/19 13:23:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Identify.hpp"

int	main(void)
{
	Base	*test;
	std::srand(static_cast<unsigned>(std::time(NULL)));
	test = generate();
	identify(test);
	delete (test);
	return (0);
}
