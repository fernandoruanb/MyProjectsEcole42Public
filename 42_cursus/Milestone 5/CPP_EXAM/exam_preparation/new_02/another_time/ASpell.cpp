/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:35:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 15:32:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {}

ASpell::~ASpell(void) {}

ASpell::ASpell(const ASpell& other): name(other.getName()), effects(other.getEffects()) {}

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}

const std::string&	ASpell::getName(void) const
{
	return (name);
}

const std::string&	ASpell::getEffects(void) const
{
	return (effects);
}
