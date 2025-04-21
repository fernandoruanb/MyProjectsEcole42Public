/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:02:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 15:55:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	the_brain = "HI THIS IS BRAIN";
	std::string	another_brain = "🧟HELLO THIS IS THE SECOND BRAIN🧠";
	std::string	*ptr_to_brain;
	std::string	&ref_to_brain = the_brain;
	std::string	delicious_brain = "🧠🧠🧠JUICY AND🧟 🧟TASTY BRAIN🧠🧠🧠";

	ptr_to_brain = NULL;
	std::cout << "🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟" << std::endl;
	if (ptr_to_brain == NULL)
		std::cout << "🧟" << "ptr_to_brain: " << "🧟🧟🧟NULL🧟🧟🧟" << std::setfill(' ') << std::setw(30) <<"🧟" << std::endl;
	ptr_to_brain = &the_brain;
	std::cout << "🧟" << "ptr_to_brain: " << *ptr_to_brain << "🧠" << std::setfill(' ') << std::setw(28) << "🧟" << std::endl;
	std::cout << "🧟" << "Ptr Address: " << ptr_to_brain << std::setfill(' ') << std::setw(33) << "🧟" << std::endl;
	std::cout << "🧟" << "ref_to_brain: " << ref_to_brain << "🧠" << std::setfill(' ') << std::setw(28) << "🧟" << std::endl;
	std::cout << "🧟" << "ref_to_brain: " << &ref_to_brain << "🧠" << std::setfill(' ') << std::setw(28) << "🧟" << std::endl;
	ref_to_brain = "🧟🧟🧟🧟🧟🧟🧟BRAAAIIINSSS🧠🧠🧠🧠🧠🧠🧠";
	std::cout << "🧟" << "ref_to_brain: " << ref_to_brain << std::setfill(' ') << std::setw(6) << "🧟" << std::endl;
	ptr_to_brain = &another_brain;
	std::cout << "🧟" << "ptr_to_new_brain: " << *ptr_to_brain << std::setfill(' ') << std::setw(8) << "🧟" << std::endl;
	ptr_to_brain = &delicious_brain;
	ref_to_brain = delicious_brain;
	std::cout << "🧟" << "ptr_to_new_brain: " << *ptr_to_brain << std::setfill(' ') << std::setw(5) << "🧟" << std::endl;
	std::cout << "🧟" << "ref_to_new_brain: " << ref_to_brain << std::setfill(' ') << std::setw(5) << "🧟" << std::endl;	
	std::cout << "🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟🧟" << std::endl;
	return (0);
}
