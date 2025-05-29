/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:14:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 12:25:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		ATarget(void);
		ATarget& operator=(const ATarget& other);
	public:
		ATarget(std::string type);
		ATarget(const ATarget& other);
		~ATarget(void);
		const std::string& getType(void) const;
		void	getHitBySpell(const ASpell* spell);
};

#endif /* ATARGET_HPP */
