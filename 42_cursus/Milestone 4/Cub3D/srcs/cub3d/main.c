/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:29:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 18:44:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	if (argc < 2)
		return (ft_putendl_fd_1("How to use: ./cub3d <map.cub>", 2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd_1("Error: unable to open file", 2));
	close(fd);
	if (!check_cub(argv[1]))
		return (1);
	game = get_t_game();
	if (!init_game(argv[1], game))
		destroy(game);
	show_textures(game);
	run_window(game);
	return (destroy(game));
}
