/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:32:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 19:32:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	show_true_game_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		ft_printf("[%i]: %s\n", index, game->true_game_map[index]);
		index++;
	}
}

void	show_textures(t_game *game)
{
	if (game->no_texture)
		ft_printf("%s\n", game->no_texture);
	if (game->so_texture)
		ft_printf("%s\n", game->so_texture);
	if (game->we_texture)
		ft_printf("%s\n", game->we_texture);
	if (game->ea_texture)
		ft_printf("%s\n", game->ea_texture);
	if (game->floor_colours)
		ft_printf("%s\n", game->floor_colours);
	if (game->ceiling_colours)
		ft_printf("%s\n", game->ceiling_colours);
	if (game->true_game_map)
		show_true_game_map(game);
}
