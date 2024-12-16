/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:05:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/16 16:18:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, unsigned char character, const char *s);

static void	handle_answer(int signum, siginfo_t *info, void *context)
{
	static int	index = 0;

	if (signum == SIGUSR2)
	{
		printf("Client received SIGUSR2.\n");
		printf("%s\n", str);
		send_bits(signum, str[index], str);
		index++;
	}
	if (index == 7)
		index = 0;
}

static int	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static void	send_bits(pid_t pid, unsigned char character, char *s)
{
	int	index;
	int	length;
	int	time;

	length = ft_strlen(s);
	time = length * 8;
	index = 7;
	while (index >= 0)
	{
		if (((character >> index) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((character >> index) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(time);
		index--;
	}
}

static int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\v' || nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			signal *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += (nptr[index] - '0');
		index++;
	}
	return (result * signal);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	t_sigaction	sa;

	if (argc != 3)
		return (1);
	sa.sa_sigaction = handle_answer;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	while (1)
	{
		pause();
	}
	return (0);
}
