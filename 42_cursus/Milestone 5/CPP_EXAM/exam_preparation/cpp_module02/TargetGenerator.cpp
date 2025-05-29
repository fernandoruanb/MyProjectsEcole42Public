/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:48:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 15:59:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) {}

void	TargetGenerator::learnTarget(ATarget* target)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(target.getType());

	if (it == targets.end())
	{
		targets[target.getType()] = target->clone();
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

ATarget*	TargetGenerator::createTargetType(const std::string &target)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(target);

	if (it != targets.end())
		return (it->second->clone());
	return (NULL);
}
