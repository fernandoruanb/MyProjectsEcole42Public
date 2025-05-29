/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:36:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 21:36:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) {}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	std::map<std::string, ATarget*>::iterator it = targets.find(target.getType());

	if (it == targets.end())
	{
		targets[target.getType()] = target->clone();
	}
}

void	TargetGenerator::forgetTargetType(const std::string& type)
{
	std::map<std::string, ATarget*>::iterator it = targets.find(type);

	if (it != targets.end())
		targets.erase(type);
}

ATarget*	TargetGenerator::createTarget(const std::string& target)
{
	std::map<std::string,ATarget*>::iterator it = targets.find(target);

	if (it != targets.end())
		return (it->second->clone());
	return (NULL);
}
