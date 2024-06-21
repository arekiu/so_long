/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:57:31 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:24 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw(t_game *game, int j, int i)
{
	put_player(game);
	if (j == game->exit_x && i == game->exit_y && game->collectables != 0)
	{
		game->map[i][j] = 'E';
		mlx_put_image_to_window(game->mlx, game->window, \
			game->exit_img, j * 40, i * 40);
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
			game->floor_img, j * 40, i * 40);
}

void	is_exit(t_game *game)
{
	if (game->collectables == 0)
	{
		game->player_won = 1;
		won_game(game);
	}
	else
		game->player_won = 2;
}

void	move_player_in_direc(t_game *game, int off_x, int off_y)
{
	int	i;
	int	j;

	move_enemy(game);
	j = game->player_x;
	i = game->player_y;
	if (game->map[i + off_y][j + off_x] == 'E')
		is_exit(game);
	else if (game->player_won != 1)
		game->player_won = 0;
	if (game->map[i + off_y][j + off_x] == 'G')
	{
		game_over(game);
		return ;
	}
	if (game->map[i + off_y][j + off_x] == 'C')
		game->collectables -= 1;
	game->map[i][j] = '0';
	game->map[i + off_y][j + off_x] = 'P';
	game->player_y = i + off_y;
	game->player_x = j + off_x;
	game->player_moves = game->player_moves + 1;
	redraw(game, j, i);
}

void	move_player(int keycode, t_game *game)
{
	int	i;
	int	j;

	j = game->player_x;
	i = game->player_y;
	if (game->player_won != 1)
	{
		if (keycode == 65362 && game->map[i - 1][j] != '1')
			move_player_in_direc(game, 0, -1);
		if (keycode == 65364 && game->map[i + 1][j] != '1')
			move_player_in_direc(game, 0, 1);
		if (keycode == 65361 && game->map[i][j - 1] != '1')
			move_player_in_direc(game, -1, 0);
		if (keycode == 65363 && game->map[i][j + 1] != '1')
			move_player_in_direc(game, 1, 0);
	}
}

//up 65362
//down 65364
//left 65361
//right 65363
