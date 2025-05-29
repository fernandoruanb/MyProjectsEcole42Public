/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:26:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:04:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {}

ATarget::ATarget(const ATarget& other): type(other.getType()) {}

ATarget::~ATarget(void) {}

const std::string&	ATarget::getType(void) const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << type << " has been " << spell.getEffects() << std::endl;
}
