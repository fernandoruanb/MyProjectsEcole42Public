/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:13:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 18:49:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct sigaction	t_sigaction;

typedef struct s_data
{
	char	*message;
	char	character;
	int		bit_count;
}	t_data;

int	ft_strlen(const char *s);

#endif /* TEST_MINITALK_H */
