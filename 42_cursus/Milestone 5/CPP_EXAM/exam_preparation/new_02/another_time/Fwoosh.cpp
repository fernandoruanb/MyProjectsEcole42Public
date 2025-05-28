/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:09:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 15:35:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const Fwoosh &other): ASpell(other.getName(), other.getEffects()) {}

Fwoosh::~Fwoosh(void) {}

ASpell*	Fwoosh::clone(void) const
{
	return new Fwoosh(*this);
}
