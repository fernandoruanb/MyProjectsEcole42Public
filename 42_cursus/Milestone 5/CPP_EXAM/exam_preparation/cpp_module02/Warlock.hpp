/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:29:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 10:39:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook spellbook;
		Warlock(void);
		Warlock(const Warlock &other);
		Warlock& operator= (const Warlock &other);
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
		void	introduce(void) const;
		void	setTitle(const std::string& title);
		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& name);
		void	launchSpell(const std::string& spell, const ATarget& target);
		const std::string& getName(void) const;
		const std::string& getTitle(void) const;
};

#endif /* WARLOCK_HPP */
