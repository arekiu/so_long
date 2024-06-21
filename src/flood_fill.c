/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:57:14 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/21 13:53:18 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (game->rows + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->rows)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
			{
				free(map_copy[i - 1]);
				i--;
			}
			free (map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	check_access(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	set_player_pos(game);
	map_copy = copy_map(game);
	if (!map_copy)
		return (-1);
	flood_fill(game, map_copy, game->player_x, game->player_y);
	while (i < game->rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (game->ava_collec != game->collectables || game->ava_exit != 1)
		return (-1);
	return (1);
}

void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (x < 1 || x > game->cols || y < 1 || y > game->rows \
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		game->ava_collec += 1;
	else if (map_copy[y][x] == 'E')
		game->ava_exit += 1;
	map_copy[y][x] = 'V';
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y - 1);
	flood_fill(game, map_copy, x, y + 1);
}
