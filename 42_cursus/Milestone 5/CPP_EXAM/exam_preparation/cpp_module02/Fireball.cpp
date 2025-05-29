/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:44:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:44:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void): ASpell("Fireball", "burnt to a crisp!") {}

Fireball::~Fireball(void) {}

Fireball::Fireball(const Fireball& other): ASpell(other.getName(), other.getEffects()) {}

ASpell*	Fireball::clone(void) const
{
	return new Fireball(*this);
}
