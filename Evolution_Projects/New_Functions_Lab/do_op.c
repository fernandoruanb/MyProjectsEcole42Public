/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:58:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/18 11:37:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	do_op(char *n1, char operator, char *n2);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = do_op(argv[1], argv[2][0], argv[3]);
	printf("%d\n", result);
	return (0);
}

int	do_op(char *n1, char operator, char *n2)
{
	int	result;

	result = 0;
	if (operator == '+')
		result = atoi(n1) + atoi(n2);
	else if (operator == '-')
		result = atoi(n1) - atoi(n2);
	else if (operator == '*')
		result = atoi(n1) * atoi(n2);
	else if (operator == '/')
	{
		if (atoi(n2) == 0)
			return (0);
		result = atoi(n1) / atoi(n2);
	}
	else if (operator == '%')
	{
		if (atoi(n2) == 0)
			return (0);
		result = atoi(n1) % atoi(n2);
	}
	return (result);
}
