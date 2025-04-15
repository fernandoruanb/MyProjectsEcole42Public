/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 15:02:23 by fruan-ba         ###   ########.fr       */
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

void	Car::startEngine(void) const override
{
	std::cout << "Car started its engine" << std::endl;
}

void	Car::stopEngine(void) const override
{
	std::cout << "Car stoped its engine" << std::endl;
}

void	Car::honk(void) const override
{
	std::cout << "Beeeeeeeeeep!" << std::endl;
}
