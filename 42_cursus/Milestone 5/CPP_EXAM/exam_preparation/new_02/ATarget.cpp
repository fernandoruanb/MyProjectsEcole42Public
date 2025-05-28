/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:44:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 18:50:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {}

ATarget::ATarget(const ATarget& other): type(other.getType()) {}

ATarget::~ATarget(void) {}

void	ATarget::getHitBySpell(const ASpell* spell) const
{
	std::cout << type << " has been " << spell.getEffects() << std::endl;
}

const std::string&	ATarget::getType(void) const
{
	return (type);
}
