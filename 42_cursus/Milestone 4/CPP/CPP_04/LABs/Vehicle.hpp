/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicle.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:10:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 17:43:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEHICLE_HPP
# define VEHICLE_HPP

# include <iostream>

class Vehicle
{
	protected:
		std::string model;
	public:
		Vehicle(void);
		Vehicle(const std::string model);
		virtual ~Vehicle(void);
		Vehicle(const Vehicle &other);
		Vehicle& operator=(const Vehicle &other);
		virtual void startEngine(void) const = 0;
		virtual void stopEngine(void) const = 0;
		virtual void honk(void) const = 0;
		std::string get_model(void) const;
};
std::ostream& operator<<(std::ostream &out, const Vehicle &other);

#endif /* VEHICLE_HPP */
