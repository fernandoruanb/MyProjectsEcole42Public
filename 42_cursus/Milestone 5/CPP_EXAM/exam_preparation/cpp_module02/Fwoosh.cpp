/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:26:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:10:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh(void) {}

Fwoosh::Fwoosh(const Fwoosh& other): ASpell(other.getName(), other.getEffects()) {}

ASpell*	Fwoosh::clone(void) const
{
	return new Fwoosh(*this);
}
