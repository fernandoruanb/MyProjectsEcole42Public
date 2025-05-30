/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:25:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:44:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void): ASpell("Polymorph", "turned into to a critter!") {}

Polymorph::~Polymorph(void) {}

Polymorph::Polymorph(const Polymorph &other): ASpell(other.getName(), other.getEffects()) {}

ASpell* Polymorph::clone(void) const
{
	return new Polymorph(*this);
}
