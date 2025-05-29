/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:26:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 14:33:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh(void) {}

Fwoosh::Fwoosh(const Fwoosh& other) name(other.getName()), effects(other.getEffects()) {}

ASpell*	clone(void) const
{
	return new Fwoosh(*this);
}
