/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:14:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:18:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include "ASpell.hpp"
# include <iostream>

class ASpell;

class ATarget
{
	private:
		ATarget(void);
		ATarget& operator=(const ATarget& other);
	protected:
		std::string type;
	public:
		ATarget(std::string type);
		ATarget(const ATarget& other);
		virtual ~ATarget(void);
		virtual ATarget* clone(void) const = 0;
		const std::string& getType(void) const;
		void	getHitBySpell(const ASpell& spell) const;
};

#endif /* ATARGET_HPP */
