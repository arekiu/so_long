/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:56:54 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 14:19:27 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/src/libft.h"
# include <mlx.h>

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
	void	*mixed_img;
	void	*dead_img;
	void	*enemy_img;
	void	*anim0_img;
	void	*anim1_img;
	void	*anim2_img;
	void	*anim3_img;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		player_moves;
	char	*str_player_moves;
	int		collectables;
	int		ava_collec;
	int		ava_exit;
	int		player_won;
	int		anim_frame;
	int		anim_counter;
}	t_game;

typedef struct s_rect_params {
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
	int	i;
	int	total_pixels;
}	t_rect_params;

int		check_map(char *map_name, t_game *game);
int		get_images(t_game *game);
void	put_images(t_game *game);
void	put_player(t_game *game);
void	set_player_pos(t_game *game);
void	move_player(int keycode, t_game *game);
int		free_map(t_game *game);
int		check_values(t_game *game);
int		check_chars(t_game *game);
int		check_access(t_game *game);
void	flood_fill(t_game *game, char **map_copy, int x, int y);
void	display_moves(t_game *game);
void	move_player_in_direc(t_game *game, int off_x, int off_y);
void	won_game(t_game *game);
void	lose_game(t_game *game);
void	game_over(t_game *game);
int		get_over_images(t_game *game);
void	move_enemy(t_game *game);

#endif
