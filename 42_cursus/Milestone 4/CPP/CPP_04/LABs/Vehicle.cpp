/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicle.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:49:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 17:43:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicle.hpp"

Vehicle::Vehicle(void) : model("aleatory_vehicle") {}

Vehicle::Vehicle(const std::string model) : model(model) {}

Vehicle::~Vehicle(void) {}

Vehicle::Vehicle(const Vehicle &other)
{
	this->model = other.model;
}

Vehicle& Vehicle::operator=(const Vehicle &other)
{
	if (this != &other)
	{
		this->model = other.model;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Vehicle &other)
{
	out << other.get_model() << std::endl;
	return (out);
}

std::string	Vehicle::get_model(void) const
{
	return (model);
}

void	Vehicle::startEngine(void) const
{
	std::cout << "A vehicle is starting its engine right now" << std::endl;
}

void	Vehicle::stopEngine(void) const
{
	std::cout << "A vehicle is stopping its engine right now" << std::endl;
}

void	Vehicle::honk(void) const
{
	std::cout << "A vehicle is honking right now" << std::endl;
}
