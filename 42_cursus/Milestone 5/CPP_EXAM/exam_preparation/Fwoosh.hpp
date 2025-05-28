/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:38:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 22:38:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class ASpell;

class Fwoosh: public ASpell
{
	private:
		Fwoosh(const Fwoosh &other);
		Fwoosh& operator=(const Fwoosh &other);
	public:
		Fwoosh(void);
		~Fwoosh(void);
		ASpell* clone(void) const;
};

#endif /* FWOOSH_HPP */
