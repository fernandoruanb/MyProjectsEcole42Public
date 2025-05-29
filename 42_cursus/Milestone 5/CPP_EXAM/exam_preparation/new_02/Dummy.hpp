/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:52:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:03:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy: public ATarget
{
	private:
		Dummy& operator=(const Dummy &other);
	public:
		Dummy(void);
		~Dummy(void);
		Dummy(const Dummy &other);
		ATarget* clone(void) const;
};

#endif /* DUMMY_HPP */
