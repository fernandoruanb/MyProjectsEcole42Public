/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:50:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 15:16:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicle.hpp"

class Car : public Vehicle
{
	private:
		std::string model;
	public:
		Car(void);
		Car(std::string model);
		~Car(void);
		Car(const Car &other);
		Car& operator=(const Car &other);
		void	startEngine(void) const override;
		void	stopEngine(void) const override;
		void	honk(void) const override;
		std::string get_car_model(void) const;
};
std::ostream& operator<<(std::ostream &out, const Car &other);
