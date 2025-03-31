/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:26:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/30 20:32:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Aeroplane
{
	public:
		int	vel = 0;


	private:
};

int	main(void)
{
	Aeroplane *av1=new Aeroplane();
	cout << av1->vel << endl;
	return (0);
}
