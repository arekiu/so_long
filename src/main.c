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
	return (-1);
}

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		on_destroy(game);
	if (keycode == 65361 || keycode == 65362 || keycode == 65363 \
		|| keycode == 65361)
		move_player(keycode, game);
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
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->player_x = 0;
	game->player_y = 0;
}

int	main(int argc, char *argv[])
{
	t_game	new_game;

	initialize_game(&new_game);

	if (argc != 2)
	{
		ft_printf("%s", "Invalid number of arguments");
		return (1);
	}
	if (check_map(argv[1], &new_game) == -1)
	{
		ft_printf("Impossible to play like this...");
		return (1);
	}
	new_game.mlx = mlx_init();
	new_game.window = mlx_new_window(new_game.mlx, (new_game.cols) * 32, \
		(new_game.rows) * 32, "so_long");
	if(get_images(&new_game) == -1)
	{
		ft_printf("error with images");
		return (1);
	}
	put_images(&new_game);
	mlx_key_hook(new_game.window, key_hook, &new_game);
	mlx_loop(new_game.mlx);
	
	return (0);
}

