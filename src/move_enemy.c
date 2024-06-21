#include "so_long.h"

void    move_enemy(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while(game->map[i][j] != '\n' && game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'G')
            {
                if (game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'C' \
                    && game->map[i][j - 1] != 'E')
                {
                    game->map[i][j - 1] = 'G';
                    game->map[i][j] = '0';
                    mlx_put_image_to_window(game->mlx, game->window, \
		                game->enemy_img, (j - 1) * 40, i * 40);
                    mlx_put_image_to_window(game->mlx, game->window, \
		                game->floor_img, j * 40, i * 40);
                    j++;
                }
                else if (game->map[i][j - 1] == '1' || game->map[i][j - 1] == 'C' \
                    || game->map[i][j - 1] != 'E')
                {
                    game->map[i][j + 1] = 'G';
                    game->map[i][j] = '0';
                    mlx_put_image_to_window(game->mlx, game->window, \
		                game->enemy_img, (j + 1) * 40, i * 40);
                    mlx_put_image_to_window(game->mlx, game->window, \
		                game->floor_img, j * 40, i * 40);
                    j++;
                }
                else if(game->map[i][j - 1] == 'P')
                    game_over(game);
            }
            j++;
        }
        i++;
    }
}