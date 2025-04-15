/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicle.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:10:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 13:32:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEHICLE_HPP
# define VEHICLE_HPP

class Vehicle
{
	protected:
		std::string model;
	public:
		virtual void startEngine(void) const = 0;
		virtual void stopEngine(void) const = 0;
		virtual void honk(void) const = 0;
		std::string get_model(void) const;
};

#endif /* VEHICLE_HPP */
