/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:02:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 18:26:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day" << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	spellbook.learnSpell(spell);
}

void	Warlock::forgetSpell(const std::string& name)
{
	spellbook.forgetSpell(name);
}

void	Warlock::launchSpell(const std::string& name, const ATarget* target)
{
	ASpell* spell = spellbook.createSpell(name);
	if (spell)
		spell->launch(target);
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

const std::string&	Warlock::getName(void) const
{
	return (name);
}

const std::string&	Warlock::getTitle(void) const
{
	return (title);
}
