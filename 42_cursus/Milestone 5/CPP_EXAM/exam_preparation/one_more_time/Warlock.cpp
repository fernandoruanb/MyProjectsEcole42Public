/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:02:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 13:17:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

void	Warlock::learnSpell(const ASpell* spell)
{
	std::map<std::string, ASpell*>::const_iterator it = spellbook.find(spell->getName());

	if (spell)
	{
		if (it == spellbook.end())
			spellbook[spell->getName()] = spell->clone();
	}
}

void	Warlock::launchSpell(const std::string spell, const ATarget &target) const
{
	std::map<std::string, ASpell*>::const_iterator it = spellbook.find(spell);

	if (it != spellbook.end())
	{
		it->second->launch(target);
	}
}

void	Warlock::forgetSpell(const std::string name)
{
	spellbook.erase(name);
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

void	Warlock::introduce(void) const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}
