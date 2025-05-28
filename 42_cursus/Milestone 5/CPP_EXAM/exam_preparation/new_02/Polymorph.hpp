/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:25:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:32:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class ASpell;

class Polymorph: public ASpell
{
	private:
		Polymorph& operator=(const Polymorph &other);
	public:
		Polymorph(void);
		~Polymorph(void);
		Polymorph(const Polymorph &other);
		ASpell* clone(void) const;
};

#endif /* POLYMORPH_HPP */
