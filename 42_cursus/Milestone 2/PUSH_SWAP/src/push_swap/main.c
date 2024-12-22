/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 12:18:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		total_numbers;

	if (argc < 2)
		return (ft_putendl_fd_1("Too few arguments.", 2));
	total_numbers = count_all_numbers(argc, argv);
	if (!parse_args(argc, argv))
		return (ft_putendl_fd_0("Invalid things found!", 2));
	return (0);
}
