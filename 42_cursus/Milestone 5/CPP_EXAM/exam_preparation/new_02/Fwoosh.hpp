/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:05:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:28:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class ASpell;

class Fwoosh: public ASpell
{
	private:
		Fwoosh& operator=(const Fwoosh &other);
	public:
		Fwoosh(void);
		~Fwoosh(void);
		Fwoosh(const Fwoosh &other);
		ASpell* Fwoosh(void) const;
};

#endif /* FWOOSH_HPP */
