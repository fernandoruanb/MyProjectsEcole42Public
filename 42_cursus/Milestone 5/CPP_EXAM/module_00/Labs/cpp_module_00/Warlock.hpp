/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:19:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 10:46:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		Warlock(const Warlock &other);
		Warlock& operator=(const Warlock &other);
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
		void	introduce(void) const;
		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;
		void	setTitle(const std::string& title);
};

#endif /* WARLOCK_HPP */
