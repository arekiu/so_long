#include "so_long.h"

int	on_destroy(t_game *game)
{
	//free_map(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{

	printf("Hello from key_hook!\n%d ", keycode);
	printf("Hello game cols\n%d ", game->cols);
	return (0);
	if (keycode == 65307)
		on_destroy(game);
}

int	main(int argc, char *argv[])
{
	t_game	new_game;

	if (argc != 2)
	{
		ft_printf("%s", "Invalid number of arguments");
		return (0);
	}
	ft_printf("map validity %d\n:",check_map(argv[1], &new_game));
	if (check_map(argv[1], &new_game) == 1)
		new_game.mlx = mlx_init();
	new_game.window = mlx_new_window(new_game.mlx, (new_game.cols) * 32, \
		(new_game.rows) * 32, "so_long");
	if(get_images(&new_game) == -1)
	{
		ft_printf("error with images");
		return (-1);
	}
	put_images(&new_game);
	mlx_key_hook(new_game.window, key_hook, &new_game);
	mlx_loop(new_game.mlx);

	return (0);
}

