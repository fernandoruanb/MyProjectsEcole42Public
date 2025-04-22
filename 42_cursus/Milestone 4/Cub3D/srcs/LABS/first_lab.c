/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_lab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:37:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 17:58:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* THIS IS A LAB */

#define TILE_SIZE 64

typedef struct s_game
{
	int	width;
	int	heigth;
	void	*mlx;
	void	*win;
	int	player_x;
	int	player_y;
}	t_game;

int	main(void)
{
	t_game	game;
	int	index;
	int	count;

	// the map on the test
	char	*map[7] = {
		"111111111111",
		"100000000001",
		"100000000001",
		"100111111101",
		"100111100001",
		"100001N11111",
		NULL
		};
	// we need to find the player location
	game.player_x = 6;
	game.player_y = 5;
	game.width = 12 * TILE_SIZE;
	game.height = 6 * TILE_SIZE;
	game.mlx = NULL;
	game.win = NULL;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width, game.heigth, "minimap");
	if (!game.mlx || !game.win)
		return (1);
	index = 0;
	while (map[index] != NULL)
	{
		count = 0;
		while (map[index][count] != '\n' && map[index][count] != '\0')
		{
			if (map[index][count] == '1')
				color = 0x000000;
			else if (map[index][count] == '0')
				color = 0x	
			mlx_pixel_put(game.mlx, game.win, index, count, color);
			count++;
		}
		index++;
	}
	return (0);
}
