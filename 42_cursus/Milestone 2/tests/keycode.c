/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:37:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 22:37:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

// cc -Wall -Werror -Wextra keycode.c -L /usr/local/lib -lmlx -lXext -lX11 -lm

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	handle_close(void *param)
{
	(void)param;
	printf("Windows closed.\n");
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error inicialização mlx.\n");
		return (1);
	}
	window = mlx_new_window(mlx, 800, 600, "Keycode Tester");
	if (!window)
	{
		printf("A janela não foi inicializada corretamente.\n");
		return (1);
	}
	mlx_key_hook(window, handle_keypress, NULL);
	mlx_hook(window, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	exit(0);
	return (0);
}
