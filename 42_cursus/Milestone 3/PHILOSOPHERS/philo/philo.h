/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:54:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 22:54:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_philo
{
	int	philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_philo;

#endif /* PHILO_H */
