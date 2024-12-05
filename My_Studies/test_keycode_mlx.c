/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_keycode_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 11:31:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>

int	key_press(int keycode, void *param)
{
	(void)param;
	printf("Keycode: %d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Keycode Test");
	mlx_key_hook(win, key_press, NULL);
	mlx_loop(mlx);
	return (0);
}
