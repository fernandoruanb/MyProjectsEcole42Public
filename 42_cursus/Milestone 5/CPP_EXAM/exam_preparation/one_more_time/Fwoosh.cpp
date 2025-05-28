/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:25:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 11:32:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh(void) {}

ASpell*	Fwoosh::clone(void) const
{
	return new Fwoosh(*this);
}
