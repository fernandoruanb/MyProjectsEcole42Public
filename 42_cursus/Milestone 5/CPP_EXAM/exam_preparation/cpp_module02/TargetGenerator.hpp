/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:33:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 15:48:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <iostream>

class ATarget;

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> targets;
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator& operator=(const TargetGenerator &other);
	public:
		TargetGenerator(void);
		~TargetGenerator(void);
		void	learnTarget(ATarget *target);
		void	forgetTarget(const std::string &type);
		ATarget*	createTargetType(const std::string &target);
}

#endif /* TARGETGENERATOR_HPP */
