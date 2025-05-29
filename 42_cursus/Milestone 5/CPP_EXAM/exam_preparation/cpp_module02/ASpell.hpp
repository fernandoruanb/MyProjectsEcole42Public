/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:01:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:00:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include "ATarget.hpp"
# include <iostream>

class ATarget;

class ASpell
{
	private:
		ASpell(void);
		ASpell& operator=(const ASpell& other);
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell(void);
		const std::string&	getName(void) const;
		const std::string&	getEffects(void) const;
		virtual ASpell* clone(void) const = 0;
		void launch(const ATarget& target) const;
};

#endif /* ASPELL_HPP */
