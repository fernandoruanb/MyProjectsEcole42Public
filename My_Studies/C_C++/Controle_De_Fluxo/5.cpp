/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:25:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/06 16:28:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void)
{
	int	num;

	cin >> num;
	if (num % 2 == 0)
		cout << "O número " << num << " é par." << endl;
	else
		cout << "O número " << num << " é ímpar." << endl;
	return (0);
}
