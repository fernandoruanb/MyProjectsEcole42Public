/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:45:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 16:35:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		ASpell(void);
		ASpell(const ASpell &other);
		ASpell& operator=(const ASpell &other);
	protected:
		std::string	name;
		std::string	effects;
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell(void);
		virtual ASpell*	clone(void) const = 0;
		void	launch(const ATarget& target) const;
		const std::string&	getName(void) const;
		const std::string&	getEffects(void) const;
};

#endif /* ASPELL_HPP */
