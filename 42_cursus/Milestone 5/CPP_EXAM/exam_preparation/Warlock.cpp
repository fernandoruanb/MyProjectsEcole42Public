/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:53:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 19:37:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day" << std::endl;
}

Warlock::~Warlock(void) 
{
	std::cout << name << ": My job here is done! " << std::endl;
}

const std::string&	Warlock::getName(void) const
{
	return (name);
}

void	Warlock::setTitle(const std::string title)
{
	this->title = title;
}

void	Warlock::introduce(void) const
{
	std::cout << this->getName() << ": I am " << this->getTitle() << std::endl;
}

const std::string&	Warlock::getTitle(void) const
{
	return (title);
}
