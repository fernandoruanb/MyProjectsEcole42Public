/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:32:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:35:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void): ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph(void) {}

Polymorph::Polymorph(const Polymorph &other): ASpell(other.getName(), other.getEffects()) {}

ASpell* Polymorph::clone(void) const
{
	return new Polymorph(*this);
}
