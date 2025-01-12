/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:54:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 10:01:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_philo
{
	pthread_mutex_t	mutex;
	long				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long				meals_eaten;
	long				philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				must_eat_time;
	long				forks;
}	t_philo;

int		ft_putendl_fd_1(const char *s, int fd);
int		ft_putendl_fd_0(const char *s, int fd);
char	*ft_putendl_fd_n(const char *s, int fd);
int		is_valid_number(const char *s);
int		parse_args(int argc, char **argv, t_philo *philosophers);
long	ft_atol(const char *nptr);
void	put_on_struct(int index, int captured_number, t_philo *philo);
int		ft_isdigit(char c);
void	show_philo_struct(t_philo *philo);

#endif /* PHILO_H */
