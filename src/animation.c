/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:50:07 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 15:02:08 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_over_images(t_game *game)
{
	game->anim0_img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/grave0.xpm", &game->img_width, &game->img_height);
	game->anim1_img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/grave1.xpm", &game->img_width, &game->img_height);
	game->anim2_img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/grave2.xpm", &game->img_width, &game->img_height);
	game->anim3_img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/grave3.xpm", &game->img_width, &game->img_height);
	if (!game->anim0_img || !game->anim1_img \
		|| !game->anim2_img || !game->anim3_img)
		return (-1);
	return (0);
}

void	display_frame(t_game *game)
{
	void	*current_img;

	if (game->anim_frame == 0)
		current_img = game->anim0_img;
	else if (game->anim_frame == 1)
		current_img = game->anim1_img;
	else if (game->anim_frame == 2)
		current_img = game->anim2_img;
	else
		current_img = game->anim3_img;
	mlx_put_image_to_window(game->mlx, game->window, \
		current_img, game->player_x * 40, game->player_y * 40);
}

int	animation_handler(t_game *game)
{
	game->anim_counter++;
	if (game->anim_counter > 3000)
	{
		game->anim_counter = 0;
		game->anim_frame++;
		display_frame(game);
		if (game->anim_frame > 3)
		{
			game->player_won = 1;
			return (0);
		}
	}
	return (1);
}

void	game_over(t_game *game)
{
	game->anim_frame = 0;
	game->anim_counter = 0;
	display_frame(game);
	mlx_loop_hook(game->mlx, (int (*)())animation_handler, game);
	lose_game(game);
}
