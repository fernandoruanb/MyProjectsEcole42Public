/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:40:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 14:48:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	operator;
	int		result;

	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		operator = argv[2][0];
		result = 0;
		if (operator == '+')
			result = num1 + num2;
		else if (operator == '-')
			result = num1 - num2;
		else if (operator == '*')
			result = num1 * num2;
		else if (operator == '/' && num2 != 0)
			result = num1 / num2;
		else if (operator == '%' && num2 != 0)
			result = num1 % num2;
		printf("%d\n", result);
	}
	return (0);
}
