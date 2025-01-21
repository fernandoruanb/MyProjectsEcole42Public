/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/21 16:28:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/microshell.h"

int	main(int argc, char **argv, char **envp)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (argv[index] && ft_strcmp(argv[index], "|") && ft_strcmp(argv[index], ";"))
			index++;
		if (index)
			status = execute_command(argv, index, envp);
	}
	return (status);
}
