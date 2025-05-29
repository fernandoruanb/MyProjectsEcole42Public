/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:47:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:58:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <map>

class ATarget;

class TargetGenerator
{
	private:
		std::map<std::string,ATarget*> targets;
		TargetGenerator(const TargetGenerator& other);
		TargetGenerator operator=(const TargetGenerator &others);
	public:
		TargetGenerator(void);
		~TargetGenerator(void);
		void learnTargetType(ATarget *target);
		void forgetTarget(const std::string type);
		ATarget* createTarget(const std::string target);
};

#endif /* TARGETGENERATOR_HPP */
