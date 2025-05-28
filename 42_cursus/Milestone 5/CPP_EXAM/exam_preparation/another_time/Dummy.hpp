/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:52:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 14:59:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
	private:
		Dummy&	operator=(const Dummy& target);
	public:
		Dummy(void);
		Dummy(const Dummy &other);
		virtual ~Dummy(void);
		ATarget* clone(void) const;
};

#endif /* DUMMY_HPP */
