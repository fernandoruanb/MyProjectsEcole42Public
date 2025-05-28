/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:57:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 11:36:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {}

ATarget::~ATarget(void) {}

ATarget::ATarget(const ATarget& other): type(other.getType()) {}

const std::string&	ATarget::getType(void) const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << std::endl;
}
