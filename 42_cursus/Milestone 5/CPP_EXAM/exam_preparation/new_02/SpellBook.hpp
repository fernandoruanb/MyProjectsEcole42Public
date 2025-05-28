/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:13:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 19:49:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <map>
# include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*> spells;
		SpellBook& operator=(const SpellBook &other);
	public:
		SpellBook(void);
		~SpellBook(void);
		SpellBook(const SpellBook &other);
		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& name);
		ASpell*	createSpell(const std::string& name);
};

#endif /* SPELLBOOK_HPP */
