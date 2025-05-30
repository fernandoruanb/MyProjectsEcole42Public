/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:28:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 16:59:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	put_on_struct(int index, int captured_number, t_philo *philo)
{
	if (index == 1 && captured_number > 200)
		return (0);
	if (index == 1)
		philo->c_ph = captured_number;
	else if (index == 2)
		philo->t_die = captured_number;
	else if (index == 3)
		philo->t_eat = captured_number;
	else if (index == 4)
		philo->t_sleep = captured_number;
	else if (index == 5)
		philo->me_time = captured_number;
	if (philo->args < 5)
		philo->me_time = -1;
	philo->tl_meal = 0;
	return (1);
}
