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
}	t_game;

int		check_map(char *map_name, t_game *game);
int		get_images(t_game *game);
void	put_images(t_game *game);

#endif
