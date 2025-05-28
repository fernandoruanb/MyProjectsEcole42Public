/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:11:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:28:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const Fwoosh &other): ASpell(other.getName(), other.getEffects()) {}

Fwoosh::~Fwoosh(void) {}

ASpell*	Fwoosh::Fwoosh(void) const
{
	return new Fwoosh(*this);
}
