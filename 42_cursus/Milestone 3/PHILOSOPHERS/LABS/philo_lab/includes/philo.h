/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:54:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 16:06:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t		*mutex;
	int					args;
	long				clock;
	long				num;
	long				id;
	long				l_time;
	long				tl_meal;
	long				m_eaten;
	long				c_ph;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	long				me_time;
	pthread_mutex_t		*forks;
	struct s_philo		*philo_ids;
	struct timeval		time;
	struct s_monitor	*flag;
}	t_philo;

typedef struct s_monitor
{
	int	died;
}	t_monitor;

int		ft_putendl_fd_1(const char *s, int fd);
int		ft_putendl_fd_0(const char *s, int fd);
char	*ft_putendl_fd_n(const char *s, int fd);
int		is_valid_number(const char *s);
int		parse_args(int argc, char **argv, t_philo *philosophers);
long	ft_atol(const char *nptr);
void	put_on_struct(int index, int captured_number, t_philo *philo);
int		ft_isdigit(char c);
void	show_philo_struct(t_philo *philo);
int		init_each_philo_fork(t_philo *philo);
int		init_each_philo_struct(t_philo *philo);
int		clean_forks(t_philo *philo);
int		clean_philo_struct(t_philo *philo);
int		lets_go(t_philo *ph);
int		init_each_philo_die_mutex(t_philo *philo);
void	clean_die_mutexes(t_philo *philo);
long	get_time(t_philo *philo);
long	new_time(t_philo *ph);
int		anyone_death(t_philo *ph);
void	try_fork_1(t_philo *ph);
void	try_fork_2(t_philo *ph);

#endif /* PHILO_H */
