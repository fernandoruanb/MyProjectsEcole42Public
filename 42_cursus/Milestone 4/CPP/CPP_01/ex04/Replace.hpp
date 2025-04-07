/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:01:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 15:14:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

class	Replace
{
	private:
		std::string	input;
		std::string	s1;
		std::string	s2;
	public:
		Replace();
		~Replace();
		void	replace(std::string input, std::string s1, std::string s2) const;
};

#endif /* REPLACE_HPP */
