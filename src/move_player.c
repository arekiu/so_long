#include "so_long.h"

void    move_player_up(t_game *game, int i, int j)
{
    if (game->map[i - 1][j] == 'C')
    {
        game->collectables = game->collectables - 1;
    }
    game->map[i][j] = '0';
    game->map[i - 1][j] = 'P';
    game->player_y = i - 1;
    game->player_moves = game->player_moves + 1;
    put_player(game);
    mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, i * 32);
        ft_printf("player position [%d][%d]\n", game->player_y, game->player_x);

}

void    move_player_down(t_game *game, int i, int j)
{
    if (game->map[i + 1][j] == 'C')
    {
        game->collectables = game->collectables - 1;
    }
    game->map[i][j] = '0';
    game->map[i + 1][j] = 'P';
    game->player_y = i + 1;
    game->player_moves = game->player_moves + 1;
    put_player(game);
    mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, i * 32);
        ft_printf("player position [%d][%d]\n", game->player_y, game->player_x);

}

void    move_player_left(t_game *game, int i, int j)
{
    if (game->map[i][j - 1] == 'C')
    {
        game->collectables = game->collectables - 1;
    }
    game->map[i][j] = '0';
    game->map[i][j - 1] = 'P';
    game->player_x = j - 1;
    game->player_moves = game->player_moves + 1;
    put_player(game);
    mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, i * 32);
        ft_printf("player position [%d][%d]\n", game->player_y, game->player_x);

}

void    move_player_right(t_game *game, int i, int j)
{
    if (game->map[i][j + 1] == 'C')
    {
        game->collectables = game->collectables - 1;
    }
    game->map[i][j] = '0';
    game->map[i][j + 1] = 'P';
    game->player_x = j + 1;
    game->player_moves = game->player_moves + 1;
    put_player(game);
    mlx_put_image_to_window(game->mlx, game->window, \
		game->floor_img, j * 32, i * 32);
        ft_printf("player position [%d][%d]\n", game->player_y, game->player_x);

}

void    move_player(int keycode, t_game *game)
{
    ft_printf("keycode is %d", keycode);
    ft_printf("player position [%d][%d]", game->player_y, game->player_x);
    ft_printf("LOS COLEC %d", game->collectables);
    int i;
    int j;

    j = game->player_x;
    i = game->player_y;

    if (keycode == 65362 && game->map[i - 1][j] != '1')
        move_player_up(game, i, j);
    if (keycode == 65364 && game->map[i + 1][j] != '1')
        move_player_down(game, i, j);
    if (keycode == 65361 && game->map[i][j - 1] != '1')
        move_player_left(game, i, j);
    if (keycode == 65363 && game->map[i][j + 1] != '1')
        move_player_right(game, i, j);
}

//up 65362
//down 65364
//left 65361
//right 65363
