/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:26:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 12:32:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget: type(type) {}

ATarget::ATarget(const ATarget& other): type(type) {}

ATarget::~ATarget(void) {}

const std::string&	getType(void) const
{
	return (type);
}

void	getHitBySpell(const ASpell* spell)
{
	std::cout << type << " has been " << spell.getEffects() << std::endl;
}
