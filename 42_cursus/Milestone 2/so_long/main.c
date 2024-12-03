/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:01:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/03 15:14:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_putstr_fd("Error: Número inválido de argumentos.\n", 2);
		ft_putstr_fd("Uso: ./so_long <mapa.ber>\n", 2);
		return (EXIT_FAILURE);
	}
	return (0);
}
