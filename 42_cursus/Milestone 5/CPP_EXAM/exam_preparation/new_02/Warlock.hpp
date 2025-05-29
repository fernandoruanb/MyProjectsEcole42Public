/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 18:23:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "SpellBook.hpp"
# include <iostream>
# include "ATarget.hpp"
# include "ASpell.hpp"

class ATarget;

class Warlock
{
	private:
		Warlock(void);
		SpellBook spellbook;
		std::string	name;
		std::string	title;
		Warlock(const Warlock &other);
		Warlock& operator=(const Warlock &other);
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
		void	setTitle(const std::string &title);
		void	introduce(void) const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(const std::string& name);
		void	launchSpell(const std::string& name, const ATarget& target);
		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;
};

#endif /* WARLOCK_HPP */
