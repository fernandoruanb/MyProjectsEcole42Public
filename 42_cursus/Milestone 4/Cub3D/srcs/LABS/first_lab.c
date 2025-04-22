/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_lab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:37:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 14:53:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* THIS IS A LAB */

#define TILE_SIZE 64

typedef struct s_game
{
	int	width;
	int	heigth;
	int	player_x;
	int	player_y;
}	t_game;

int	main(void)
{
	t_game	game;
	// the map on the test
	char	*map[6] = {
		"111111111111",
		"100000000001",
		"100000000001",
		"100111111101",
		"100111100001",
		"100001N11111"
		};
	// we need to fiind the player location
	game.player_x = 6;
	game.player_y = 5;
	game.width = 12 * TILE_SIZE;
	game.height = 6 * TILE_SIZE;
	return (0);
}
