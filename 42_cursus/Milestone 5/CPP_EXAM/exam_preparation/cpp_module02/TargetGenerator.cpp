/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:48:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:36:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) 
{
	std::map<std::string,ATarget*>::iterator it = targets.begin();
	std::map<std::string,ATarget*>::iterator result;

	while (it != targets.end())
	{
		result = it;
		delete result->second;
		++it;
	}
}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(target->getType());

	if (it == targets.end())
	{
		targets[target->getType()] = target->clone();
	}
}

void	TargetGenerator::forgetTarget(const std::string &type)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(type);

	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string &target)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(target);

	if (it != targets.end())
		return (it->second->clone());
	return (NULL);
}
