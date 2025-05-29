/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:43:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:31:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) 
{
	std::map<std::string,ASpell*>::iterator it = spellbook.begin();
	std::map<std::string,ASpell*>::iterator result;

	while (it != spellbook.end())
	{
		result = it;
		delete result->second;
		++it;
	}
}

void	SpellBook::learnSpell(ASpell* spell)
{
	std::map<std::string, ASpell*>::iterator it = spellbook.find(spell->getName());

	if (it == spellbook.end())
	{
		spellbook[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(const std::string& name)
{
	std::map<std::string,ASpell*>::iterator it = spellbook.find(name);

	if (it != spellbook.end())
	{
		delete it->second;
		spellbook.erase(it);
	}
}

ASpell*	SpellBook::createSpell(const std::string& spell)
{
	std::map<std::string,ASpell*>::iterator it = spellbook.find(spell);

	if (it != spellbook.end())
	{
		return (it->second->clone());
	}
	return (NULL);
}
