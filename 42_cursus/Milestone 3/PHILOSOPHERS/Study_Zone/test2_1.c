/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:05:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 12:06:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>

int	main(void)
{
	int	pid;
	int	target;

	target = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		printf("%d\n", ++target);
	sleep(2);
	printf("Hello from process %d\n", getpid());
	if (pid != 0)
		wait(NULL);
	return (0);
}
