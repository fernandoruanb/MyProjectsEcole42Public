/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:56:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 08:37:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_putstr_fd_1("Too few arguments.\n", 2));
	if (!parse_args(argc, argv))
		return (ft_putstr_fd_1("Invalid numbers detected!\n", 2));
	return (0);
}
