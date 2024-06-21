#include "so_long.h"

void	put_items(char *line, t_game *game, int index)
{
	int		j;

	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
	{
		if (line[j] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->wall_img, j * 40, index * 40);
		else if (line[j] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 40, index * 40);
		else if (line[j] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->treasure_img, j * 40, index * 40);
		else if (line[j] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->exit_img, j * 40, index * 40);
		j++;
	}
}
void	put_player(t_game *game)
{
	if (game->player_won == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
					game->dead_img, game->player_x * 40, game->player_y * 40);
	else if (game->player_won == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
					game->mixed_img, game->player_x * 40, game->player_y * 40);				
	else
		mlx_put_image_to_window(game->mlx, game->window, \
					game->player_img, game->player_x * 40, game->player_y * 40);
}
void	set_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while(game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}	
		i++;
	}
}

void	put_images(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i] != NULL)
	{
		put_items(game->map[i], game, i);
		i++;
	}
	put_player(game);
}

int	get_images(t_game *game)
{
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm", &game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &game->img_width, &game->img_height);
	game->treasure_img = mlx_xpm_file_to_image(game->mlx, "./assets/book.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./assets/cat.xpm", &game->img_width, &game->img_height);
	game->dead_img = mlx_xpm_file_to_image(game->mlx, "./assets/dead.xpm", &game->img_width, &game->img_height);
	game->mixed_img = mlx_xpm_file_to_image(game->mlx, "./assets/mixed.xpm", &game->img_width, &game->img_height);

	if (!game->floor_img || !game->wall_img || !game->treasure_img || !game->exit_img || 
	    !game->player_img || !game->dead_img || !game->mixed_img)
		return (-1);

	return (0);
}
