/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:33:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 08:58:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	char	*message;
	int		count_bits;
	char	current_char;
}	t_data;

typedef struct sigaction	t_sigaction;

void	*handle_signal(int signal, siginfo_t *info, void *context);
int		ft_atoi(const char *str);
void	send_message(int pid, char *message);

#endif /* MINITALK_H */
