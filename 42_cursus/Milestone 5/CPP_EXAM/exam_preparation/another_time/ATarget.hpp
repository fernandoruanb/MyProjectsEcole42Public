/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:40:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 15:34:06 by fruan-ba         ###   ########.fr       */
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
		ATarget& operator=(const ATarget& target);
	protected:
		std::string type;
	public:
		ATarget(std::string type);
		ATarget(const ATarget& other);
		virtual ATarget* clone(void) const = 0;
		virtual ~ATarget(void);
		void	getHitBySpell(const ASpell& spell) const;
		const std::string&	getType(void) const;
};

#endif /* ATARGET_HPP */
