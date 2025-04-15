/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:17:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 17:22:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicle.hpp"
#include "Car.hpp"

int	main(void)
{
	Vehicle* v1 = new Car("Lamborguini");

	v1->startEngine();
	delete(v1);
	return (0);
}
