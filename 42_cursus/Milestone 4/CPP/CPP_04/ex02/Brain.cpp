/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:17:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 19:11:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : total(0)
{
	std::cout << "Brain empty constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	int	index;

	index = 0;
	std::cout << "Copy Brain constructor called" << std::endl;
	while (index < 100)
	{
		ideas[index] = other.ideas[index];
		index++;
	}
	this->total = other.total;
}

void	Brain::get_an_idea(int index) const
{
	--index;;
	if (index < 0 || index >= 100 || ideas[index].empty())
	{
		std::cerr << "The index is invalid. The brain only can support 100 ideas at the moment" << std::endl;
		return ;
	}
	std::cout << ideas[index] << std::endl;
}

void	Brain::show_all_ideas(void) const
{
	int	index;

	index = 0;
	while (index < 100)
	{
		if (ideas[index].empty())
			break ;
		std::cout << ideas[index] << std::endl;
		index++;
	}
}

void	Brain::add_new_idea(void)
{
	if (total >= 100)
	{
		std::cout << "Your brain is full of ideas" << std::endl;
		std::cout << "You can't create a new idea now" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "Please, type the new idea: ";
	std::getline(std::cin, ideas[total]);
	if (ideas[total].empty())
	{
		std::cin.clear();
		return ;
	}
	if (std::cin.eof())
		return ;
	total++;
}

Brain& Brain::operator=(const Brain &other)
{
	int	index;

	index = 0;
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		while (index < 100)
		{
			ideas[index] = other.ideas[index];
			index++;
		}
		this->total = other.total;
	}
	return (*this);
}
