/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:40:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 09:47:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

HumanA::HumanA(std::string name, std::string weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA() {}

HumanA:: const std::string& getType(void) const
{
	return (type);
}

HumanA:: void setType(std::string type)
{
	this->type = type;
}
