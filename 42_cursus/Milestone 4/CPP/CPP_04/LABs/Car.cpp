/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 17:40:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Car.hpp"

Car::Car(void) : model("aleatory_car") {}

Car::Car(std::string model) : model(model) {}

Car::~Car(void) {}

Car::Car(const Car &other)
{
	this->model = other.model;
}

Car& Car::operator=(const Car &other)
{
	if (this != &other)
	{
		this->model = other.model;
	}
	return (*this);
}

void	Car::startEngine(void) const
{
	std::cout << "Car started its engine" << std::endl;
}

void	Car::stopEngine(void) const
{
	std::cout << "Car stoped its engine" << std::endl;
}

std::string	Car::get_car_model(void) const
{
	return (model);
}

std::ostream& operator<<(std::ostream &out, const Car &other)
{
	out << other.get_car_model() << std::endl;
	return (out);
}

void	Car::honk(void) const
{
	std::cout << "Beeeeeeeeeep!" << std::endl;
}
