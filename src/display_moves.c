/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:56:39 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 14:19:07 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_rectangle(t_game *game, t_rect_params *params)
{
	void	*rect_img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;

	rect_img = mlx_new_image(game->mlx, params->width, params->height);
	data = (int *)mlx_get_data_addr(rect_img, &bpp, &size_line, &endian);
	params->total_pixels = params->width * params->height;
	params->i = 0;
	while (params->i < params->total_pixels)
	{
		data[params->i] = params->color;
		params->i++;
	}
	mlx_put_image_to_window(game->mlx, game->window, rect_img, \
		params->x, params->y);
	mlx_destroy_image(game->mlx, rect_img);
	params->i = 0;
	params->total_pixels = 0;
}

void	display_moves(t_game *game)
{
	char			*moves;
	char			*new_str;
	t_rect_params	params;

	params.x = 10;
	params.y = 3;
	params.width = 80;
	params.height = 20;
	params.color = 0x000000;
	moves = ft_itoa(game->player_moves);
	if (!moves)
		return ;
	new_str = ft_strjoin("Moves: ", moves);
	free(moves);
	if (!new_str)
		return ;
	free(game->str_player_moves);
	game->str_player_moves = new_str;
	draw_rectangle(game, &params);
	mlx_string_put(game->mlx, game->window, 18, 18, 0x00FF0000, \
		game->str_player_moves);
}

void	won_game(t_game *game)
{
	char			*message;
	t_rect_params	params;

	params.x = 100;
	params.y = 3;
	params.width = 360;
	params.height = 20;
	params.color = 0x000000;
	message = "You did it. Now you are Necromancer between life and death.";
	draw_rectangle(game, &params);
	mlx_string_put(game->mlx, game->window, 108, 18, 0x00FF0000, message);
}

void	lose_game(t_game *game)
{
	char			*message;
	t_rect_params	params;

	params.x = 100;
	params.y = 3;
	params.width = 100;
	params.height = 20;
	params.color = 0x000000;
	message = "Bad luck :()";
	draw_rectangle(game, &params);
	mlx_string_put(game->mlx, game->window, 108, 18, 0x00FF0000, message);
}
