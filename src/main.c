/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:57:52 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 17:23:16 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return (-1);
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	free(game->str_player_moves);
	game->str_player_moves = NULL;
	return (-1);
}

int	on_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->treasure_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->dead_img);
	mlx_destroy_image(game->mlx, game->mixed_img);
	mlx_destroy_image(game->mlx, game->enemy_img);
	mlx_destroy_image(game->mlx, game->anim0_img);
	mlx_destroy_image(game->mlx, game->anim1_img);
	mlx_destroy_image(game->mlx, game->anim2_img);
	mlx_destroy_image(game->mlx, game->anim3_img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		on_destroy(game);
	if (keycode == 65361 || keycode == 65362 || keycode == 65363 \
		|| keycode == 65364)
	{
		move_player(keycode, game);
		display_moves(game);
	}
	return (0);
}

void	initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->floor_img = NULL;
	game->wall_img = NULL;
	game->treasure_img = NULL;
	game->exit_img = NULL;
	game->player_img = NULL;
	game->mixed_img = NULL;
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->collectables = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->player_moves = 0;
	game->img_height = 40;
	game->img_width = 40;
	game->ava_collec = 0;
	game->ava_exit = 0;
	game->player_won = 0;
	game->str_player_moves = ft_strdup("Moves: 0");
}

int	main(int argc, char *argv[])
{
	t_game	new_game;

	if (argc != 2)
	{
		ft_printf("Error!!!\nInvalid number of arguments");
		return (1);
	}
	initialize_game(&new_game);
	if (check_map(argv[1], &new_game) == -1)
	{
		ft_printf("Error!!!\nInvalid map...");
		return (1);
	}
	new_game.mlx = mlx_init();
	new_game.window = mlx_new_window(new_game.mlx, (new_game.cols) * 40, \
		(new_game.rows) * 40, "so_long");
	if (get_images(&new_game) == -1)
	{
		ft_printf("Error!!!\nProblem charging images");
		return (1);
	}
	mlx_key_hook(new_game.window, key_hook, &new_game);
	mlx_hook(new_game.window, 17, 0, on_destroy, &new_game);
	mlx_loop(new_game.mlx);
	return (0);
}
