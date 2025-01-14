/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:11:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 19:26:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	show_philo_struct(t_philo *philo)
{
	printf("Philosophers's number: %ld\n", philo->num);
	printf("Philosophers: %ld\n", philo->c_ph);
	printf("Time to die: %ld\n", philo->t_die);
	printf("Time to eat: %ld\n", philo->t_eat);
	printf("Time to sleep: %ld\n", philo->t_sleep);
	printf("Must eat times: %ld\n", philo->me_time);
	printf("Meals eaten: %ld\n", philo->m_eaten);
	printf("Time last meal: %ld\n", philo->tl_meal);
}
