/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:16:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:22:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	error(void);
		void	warning(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif /* HARL_HPP */
