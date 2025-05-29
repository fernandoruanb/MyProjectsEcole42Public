/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:34:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 14:44:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class ASpell;

class Fireball: public ASpell
{
	private:
		Fireball& operator=(const Fireball& other);
	public:
		Fireball(void);
		~Fireball(void);
		Fireball(const Fireball &other);
		ASpell* clone(void) const;
};

#endif /* FIREBALL_HPP
