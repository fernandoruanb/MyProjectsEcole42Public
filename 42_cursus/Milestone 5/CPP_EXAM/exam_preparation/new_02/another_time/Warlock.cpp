/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:51:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 15:31:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day!" << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
}

void	Warlock::learnSpell(const ASpell* spell)
{
	std::map<std::string, ASpell*>::const_iterator it = spellbook.find(spell->getName());

	if (it == spellbook.end())
	{
		spellbook[spell->getName()] = spell->clone();
	}
}

void	Warlock::forgetSpell(const std::string name)
{
	std::map<std::string, ASpell*>::const_iterator it = spellbook.find(name);

	if (it != spellbook.end())
	{
		spellbook.erase(name);
	}
}

void	Warlock::launchSpell(const std::string spell, ATarget& target) const
{
	std::map<std::string, ASpell*>::const_iterator it = spellbook.find(spell);

	if (it != spellbook.end())
	{
		it->second->launch(target);
	}
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

const std::string&	Warlock::getName(void) const
{
	return (name);
}

const std::string&	Warlock::getTitle(void) const
{
	return (title);
}
