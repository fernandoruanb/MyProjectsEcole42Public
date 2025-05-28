/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:37:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 13:20:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(void): effects("fwooshed") {}

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {}

ASpell::~ASpell(void) {}

ASpell::ASpell(const ASpell& other): name(other.getName()), effects(other.getEffects()) {}

const	std::string&	ASpell::getName(void) const
{
	return (name);
}

const	std::string&	ASpell::getEffects(void) const
{
	return (effects);
}

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
