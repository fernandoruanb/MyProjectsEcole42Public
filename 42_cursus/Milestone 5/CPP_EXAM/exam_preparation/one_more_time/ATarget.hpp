/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:45:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 13:32:03 by fruan-ba         ###   ########.fr       */
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
		ATarget& operator=(const ATarget &other);
	protected:
		std::string	type;
	public:
		ATarget(std::string type);
		virtual ~ATarget(void);
		ATarget(const ATarget &other);
		virtual ATarget* clone(void) const = 0;
		void	getHitBySpell(const ASpell& spell) const;
		const std::string& getType(void) const;
};

#endif /* ATARGET_HPP */
