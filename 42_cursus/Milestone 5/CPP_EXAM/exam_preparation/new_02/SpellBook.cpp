/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:23:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 19:50:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) {}

SpellBook(const SpellBook &other) 
{
	(void)other;
}

void	SpellBook::learnSpell(ASpell* spell)
{
	std::map<std::string,ASpell*>::iterator it = spells.find(spell.getName());

	if (it == spells.end())
	{
		spells[spell.getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(const std::string& name)
{
	std::map<std::string,ASpell*>::iterator it = spells.find(name);

	if (it != spells.end())
	{
		spells.erase(name);
	}
}

ASpell*	SpellBook::createSpell(const std::string& name)
{
	std::map<std::string, ASpell*>::const_iterator it = spells.find(name);

	if (it != spells.end())
	{
		return (it->second->clone());
	}
	return (NULL);
}
