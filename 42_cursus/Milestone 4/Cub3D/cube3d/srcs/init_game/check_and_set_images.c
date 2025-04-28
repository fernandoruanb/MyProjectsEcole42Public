/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:54:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/28 12:04:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_all_images_addr(t_game *game)
{
	game->no_addr = mlx_get_data_addr(game->no_img, &game->bpp_no,
			&game->line_length_no, &game->endian_no);
	if (!game->no_addr)
		return (0);
	game->so_addr = mlx_get_data_addr(game->so_img, &game->bpp_so,
			&game->line_length_so, &game->endian_so);
	if (!game->so_addr)
		return (0);
	game->we_addr = mlx_get_data_addr(game->we_img, &game->bpp_we,
			&game->line_length_we, &game->endian_we);
	if (!game->we_addr)
		return (0);
	game->ea_addr = mlx_get_data_addr(game->ea_img, &game->bpp_ea,
			&game->line_length_ea, &game->endian_ea);
	if (!game->ea_addr)
		return (0);
	return (1);
}

int	check_and_set_images(t_game *game)
{
	int	width;
	int	heigth;

	game->no_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->no_texture, &width, &heigth);
	if (!game->no_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->so_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->so_texture, &width, &heigth);
	if (!game->so_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->we_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->we_texture, &width, &heigth);
	if (!game->we_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->ea_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->ea_texture, &width, &heigth);
	if (!game->ea_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	if (!get_all_images_addr(game))
		return (0);
	return (1);
}
