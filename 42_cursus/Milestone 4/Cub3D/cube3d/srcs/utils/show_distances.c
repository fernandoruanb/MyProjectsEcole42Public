/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_distances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:40:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 22:40:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	show_distances(t_game *game)
{
	printf("Distance: %f\n\n", game->distance);
	printf("Distance Left: %f\n\n", game->distance_l);
	printf("Distance Right: %f\n\n", game->distance_r);
}
