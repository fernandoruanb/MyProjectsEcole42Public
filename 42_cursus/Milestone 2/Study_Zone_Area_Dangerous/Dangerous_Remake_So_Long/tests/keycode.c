/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:40:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 08:47:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	printf("Keypress: %d\n", keycode);
	return (0);
}

int	handle_close(void *param)
{
	(void)param;
	printf("Janela fechada\n");
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("A conexão com mlx não foi criada.\n");
		return (1);
	}
	win = mlx_new_window(mlx, 800, 600, "keycode");
	if (!win)
	{
		printf("A conexão com a janela não foi criada.\n");
		return (1);
	}
	mlx_key_hook(win, handle_keypress, NULL);
	mlx_hook(win, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	exit(0);
	return (0);
}
