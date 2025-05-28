/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:33:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 19:49:16 by fruan-ba         ###   ########.fr       */
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
		ASpell(const ASpell& other);
		virtual ASpell* clone(void) const = 0;
		const std::string&	getName(void) const;
		const std::string&	getEffects(void) const;
		void	launch(const ATarget &target) const;
};

#endif /* ASPELL_HPP */
