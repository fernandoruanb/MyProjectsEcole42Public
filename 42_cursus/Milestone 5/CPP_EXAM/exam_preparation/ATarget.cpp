/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:46:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 20:46:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {}

ATarget::~ATarget(void) {}

const std::string&	getType(void) const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects();
}
