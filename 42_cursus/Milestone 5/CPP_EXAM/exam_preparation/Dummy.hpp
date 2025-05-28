/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:58:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 20:58:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
	private:
		Dummy(const Dummy& other);
		Dummy& operator=(const Dummy &other);
	public:
		Dummy(void);
		~Dummy(void);
		virtual Dummy* clone(void) const;	
};

#endif /* DUMMY_HPP */
