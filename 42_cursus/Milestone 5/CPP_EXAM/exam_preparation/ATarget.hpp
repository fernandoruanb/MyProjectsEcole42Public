/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:54:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 19:59:15 by fruan-ba         ###   ########.fr       */
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
		ATarget(const ATarget &other);
		ATarget& operator=(const ATarget &other);
	protected:
		std::string type;
	public:
		ATarget(std::string type);
		virtual ~ATarget(void);
		void	getHitBySpell(const ASpell& spell) const;
		virtual clone(void) const = 0;
		const std::string& getType(void) const;
};
