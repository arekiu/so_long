#include "so_long.h"

static int	check_rows(char *map_name, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (-1);
	}
	while (line != NULL)
	{
		game->rows = game->rows + 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->rows < 3)
	{
		ft_printf("Map too small");
		return (-1);
	}
	return (1);
}

static int	fill_map(char *map_name, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
		{
			close (fd);
			free_map(game);
			return (-1);
		}
		i++;
	}
	game->map[i] = NULL;
	close (fd);
	return (1);
}

static int	check_cols(t_game *game)
{
	int		i;

	i = 0;
	game->cols = (int)ft_strlen(game->map[i]) - 1;
	while (game->map[i] != NULL)
	{
		if (((int)ft_strlen(game->map[0]) - 1) != game->cols || game->cols < 5)
		{
			ft_printf("Invalid map size\n");
			return (-1);
		}
		i++;
	}
	if (i < 3)
	{
		ft_printf("Invalid map size\n");
		return (-1);
	}
	return (1);
}


int	check_map(char *map_name, t_game *game)
{
	if (check_rows(map_name, game) == -1)
		return (-1);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		return (-1);
	if (fill_map(map_name, game) == -1)
	{
		free_map(game);
		return (-1);
	}
	if (check_cols(game) == -1)
	{
		free_map(game);
		return (-1);
	}
	if (check_values(game) == -1 || check_access(game) == -1)
	{
		ft_printf("Unreachable items or wrong values\n");
		free_map(game);
		return (-1);
	}
	return (1);
}
