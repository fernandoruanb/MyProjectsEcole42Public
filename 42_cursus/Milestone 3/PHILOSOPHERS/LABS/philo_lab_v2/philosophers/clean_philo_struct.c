/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_philo_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:05:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 11:52:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	clean_philo_struct(t_philo *philo)
{
	if (philo->philo_ids)
		free(philo->philo_ids);
	philo->philo_ids = NULL;
	clean_die_mutexes(philo);
	free(philo->flag);
	return (ft_putendl_fd_0("Succeed to clean philosophers' struct", 1));
}
