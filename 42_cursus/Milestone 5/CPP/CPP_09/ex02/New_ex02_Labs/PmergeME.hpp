/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:55:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/06 17:55:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <list>
# include <vector>
# include <iostream>
# include <algorithm>
# include <climits>
# include "colours.hpp"
# include <sstream>

void	sortHighVector(std::vector<unsigned int> &vectorHigh);
void	sortHighList(std::list<unsigned int> &listHigh);
void	generateVectorJacobsthal(std::vector<unsigned int> &jacobVector, size_t limit);
void	generateListJacobsthal(std::list<unsigned int> &jacobList, size_t limit);

#endif /* PMERGE_HPP */
