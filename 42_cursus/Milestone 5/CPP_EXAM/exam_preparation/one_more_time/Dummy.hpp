/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 11:20:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
	private:
		Dummy&	operator=(const Dummy &other);
	public:
		Dummy(void);
		~Dummy(void);
		Dummy(const Dummy &other);
		ATarget* clone(void) const;
};

#endif /* DUMMY_HPP */
