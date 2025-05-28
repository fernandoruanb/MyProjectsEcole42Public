/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:28:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 11:44:52 by fruan-ba         ###   ########.fr       */
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
		std::string	name;
		std::string	effects;
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell(void);
		ASpell(const ASpell& other);
		virtual ASpell* clone(void) const = 0;
		void	launch(const ATarget& target) const;
		const std::string& getName(void) const;
		const std::string& getEffects(void) const;
};

#endif /* ASPELL_HPP */
