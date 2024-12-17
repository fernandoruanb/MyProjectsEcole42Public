/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:52:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 12:53:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("The server PID is: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
