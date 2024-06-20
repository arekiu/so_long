#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/src/libft.h"
#include <mlx.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		cols;
	int		rows;
	int		img_height;
	int		img_width;
	void	*floor_img;
	void	*wall_img;
	void	*treasure_img;
	void	*exit_img;
	void	*player_img;
	int		player_x;
	int		player_y;
	int		player_moves;
	int		collectables;
	int		ava_collec;
	int		ava_exit;
}	t_game;

int		check_map(char *map_name, t_game *game);
int		get_images(t_game *game);
void	put_images(t_game *game);
void	put_player(t_game *game);
void	set_player_pos(t_game *game);
void	move_player(int keycode, t_game *game);
int		free_map(t_game *game);
int		check_values(t_game *game);
int		check_chars(t_game *game);
int check_access(t_game *game);
void flood_fill(t_game *game, char **map_copy, int x, int y);

#endif
