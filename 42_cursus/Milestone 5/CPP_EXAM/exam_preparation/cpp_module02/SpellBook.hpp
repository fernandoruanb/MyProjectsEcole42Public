/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:35:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 11:55:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include "ASpell.hpp"
# include <iostream>

class SpellBook
{
	private:
		std::map<std::string, ASpell*> spellbook;
		SpellBook(const SpellBook& spells);
		SpellBook& operator=(const SpellBook& spells);
	public:
		SpellBook(void);
		~SpellBook(void);
		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& name);
		ASpell* createSpell(const std::string& spell);
};

#endif /* SPELLBOOK_HPP */
