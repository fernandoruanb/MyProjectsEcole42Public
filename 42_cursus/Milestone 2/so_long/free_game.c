/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:58:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 11:13:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game **game)
{
	int	index;

	if ((*game)->map)
	{
		index = 0;
		while ((*game)->map[index] != NULL)
		{
			free((*game)->map[index]);
			index++;
		}
		free((*game));
	}
	if ((*game)->player_img)
		mlx_destroy_image((*game)->player_img);
	if ((*game)->floor_img)
		mlx_destroy_image((*game)->floor_img);
	if ((*game)->collectible_img)
		mlx_destroy_image((*game)->collectible_img);
	if ((*game)->exit_img)
		mlx_destroy_image((*game)->exit_img);
	if ((*game)->wall_img)
		mlx_destroy_image((*game)->wall_img);
	if ((*game)->win_ptr)
		mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	exit(0);
}
