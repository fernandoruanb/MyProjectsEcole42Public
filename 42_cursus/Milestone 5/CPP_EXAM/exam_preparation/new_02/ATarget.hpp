/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:41:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 18:45:16 by fruan-ba         ###   ########.fr       */
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
		std::string	type;
	public:
		ATarget(std::string type);
		ATarget(const ATarget &other);
		~ATarget(void);
		const std::string&	getType(void) const;
		virtual ATarget* clone(void) const = 0;
		void	getHitBySpell(const ASpell* spell) const;
};

#endif /* ATARGET_HPP */
