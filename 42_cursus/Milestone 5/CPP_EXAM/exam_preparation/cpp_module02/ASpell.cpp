/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:05:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 12:11:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {}

ASpell::~ASpell(void) {}

const std::string&	ASpell::getName(void) const
{
	return (name);
}

const std::string&	ASpell::getEffects(void) const
{
	return (effects);
}

void	ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}
