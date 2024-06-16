#include "so_long.h"

void    move_player(int keycode, t_game *game)
{
    ft_printf("keycode is %d", keycode);
    ft_printf("player position [%d][%d]", game->player_x, game->player_y);
}

//up 65362
//down 65364
//left 65361
//right 65363