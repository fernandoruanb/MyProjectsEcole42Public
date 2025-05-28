/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:43:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 15:33:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {}

ATarget::~ATarget(void) {}

ATarget::ATarget(const ATarget& other): type(other.getType()) {}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
const std::string&	ATarget::getType(void) const
{
	return (type);
}
