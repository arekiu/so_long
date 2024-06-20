#include "so_long.h"

void	draw_rectangle(t_game *game, int x, int y, int width, int height, int color)
{
	void	*rect_img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		i;

	rect_img = mlx_new_image(game->mlx, width, height);
	data = (int *)mlx_get_data_addr(rect_img, &bpp, &size_line, &endian);
	i = 0;
	while (i < width * height)
	{
		data[i] = color;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->window, rect_img, x, y);
	mlx_destroy_image(game->mlx, rect_img);
}

void	display_moves(t_game *game)
{
	char *moves;
	char *new_str;
	moves = ft_itoa(game->player_moves);
	if (!moves)
		return;
	new_str = ft_strjoin("Moves: ", moves);
	free(moves);
	if (!new_str)
		return;
	free(game->str_player_moves);
	game->str_player_moves = new_str;
	draw_rectangle(game, 10, 3, 100, 20, 0x000000);
	mlx_string_put(game->mlx, game->window, 18, 18, 0x00FF0000, game->str_player_moves);
}