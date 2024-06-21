/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:57:24 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 14:47:52 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map_and_images(t_game *game, int i, int j, int new_j)
{
	game->map[i][new_j] = 'G';
	game->map[i][j] = '0';
	mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 40, i * 40);
	mlx_put_image_to_window(game->mlx, game->window, \
		game->enemy_img, new_j * 40, i * 40);
}

void	position_handler(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'C' \
		&& game->map[i][j - 1] != 'E')
		update_map_and_images(game, i, j, j - 1);
	else if (game->map[i][j + 1] == '1' || game->map[i][j + 1] == 'C' \
		|| game->map[i][j - 1] != 'E')
		update_map_and_images(game, i, j, j + 1);
	else if (game->map[i][j - 1] == 'P')
		game_over(game);
}

void	move_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'G')
			{
				position_handler(game, i, j);
				j++;
			}
			j++;
		}
		i++;
	}
}
