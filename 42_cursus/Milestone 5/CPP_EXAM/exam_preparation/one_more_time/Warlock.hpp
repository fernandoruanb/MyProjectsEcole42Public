/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:52:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 12:11:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include "Dummy.hpp"
# include "ATarget.hpp"
# include "ASpell.hpp"
# include "Fwoosh.hpp"

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		std::map<std::string, ASpell*> spellbook;
		Warlock(void);
		Warlock(const Warlock &other);
		Warlock& operator=(const Warlock &other);
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
		void	introduce(void) const;
		void	setTitle(const std::string& title);
		void	learnSpell(const ASpell* spell);
		void	launchSpell(const std::string spell, const ATarget &target) const;
		void	forgetSpell(const std::string name);
		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;
};

#endif /* WARLOCK_HPP */
