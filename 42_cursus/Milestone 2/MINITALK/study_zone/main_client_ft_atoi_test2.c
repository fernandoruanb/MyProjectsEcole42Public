/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client_ft_atoi_test2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 11:17:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

/* Esse teste é para checar se o PID é tratado corretamente
 * mesmo que sejam caracteres especiais ou letras 
 * juntamente, agora, usando a ft_atoi que eu codei. =D */

static int	ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		printf("How to use: [PID] [MESSAGE].\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	printf("The PID: %d\n", pid);
	printf("The client's message: %s\n", argv[2]);
	return (0);
}
