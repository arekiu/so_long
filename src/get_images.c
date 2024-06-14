#include "so_long.h"

void	fill_image(char *line, t_game *game, int index)
{
	int		j;

	j = 0;
	while (line[j] != '\n')
	{
		mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, index * 32);
		if (line[j] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->wall_img, j * 32, index * 32);
		/*else if (line[j] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, index * 32);*/
		else if (line[j] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->treasure_img, j * 32, index * 32);
		else if (line[j] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->exit_img, j * 32, index * 32);
		else if (line[j] == 'P')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->player_img, j * 32, index * 32);
		j++;
	}
}

void	put_images(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i] != NULL)
	{
		fill_image(game->map[i], game, i);
		i++;
	}
}

int	get_images(t_game *game)
{
	game->img_height = 32;
	game->img_width = 32;

	game->floor_img = mlx_xpm_file_to_image(game->mlx, \
	"./assets/floor.xpm", &game->img_width, &game->img_height);
	if (game->floor_img == NULL)
		return (-1);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
	"./assets/wall.xpm", &game->img_width, &game->img_height);
	if (game->wall_img == NULL)
		return (-1);
	game->treasure_img = mlx_xpm_file_to_image(game->mlx, \
	"./assets/treasure.xpm", &game->img_width, &game->img_height);
	if (game->treasure_img == NULL)
		return (-1);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
	"./assets/fire.xpm", &game->img_width, &game->img_height);
	if (game->exit_img == NULL)
		return (-1);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
	"./assets/barrel.xpm", &game->img_width, &game->img_height);
	if (game->player_img == NULL)
		return (-1);
	return (0);
}
