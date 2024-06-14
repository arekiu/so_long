#include "so_long.h"

static int	check_size(char *map_name, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	game->cols = (int)ft_strlen(line) - 1;
	while (line != NULL)
	{
		if (((int)ft_strlen(line) - 1) != game->cols || game->cols < 5)
			return (-1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (i < 3)
		return (-1);
	return (i);
}

static int	create_map(char *map_name, t_game *game, int rows)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map_name, O_RDONLY);
	game->map = malloc(sizeof(char *) * (rows + 1));
	if (!game->map || fd < 0)
	{
		free(game->map);
		return (-1);
	}
	while (i < rows)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	return (1);
}
static int	check_chars(t_game *game, int rows)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	len;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	len = (int)ft_strlen(game->map[0]) - 1;
	while (i++ < rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1' )
			return (-1);
		if (ft_strchr(game->map[i], 'P') != 0)
			p = p + 1;
		if (ft_strchr(game->map[i], 'E') != 0)
			e = e + 1;
		if (ft_strchr(game->map[i], 'C') != 0)
			c = c + 1;
	}
	if ((p != 1) || (e != 1) || (c < 1))
		return (-1);
	return (1);
}

static int	check_values(t_game *game, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		if (i == 0 || i == rows - 1)
		{
			j = 0;
			while (game->map[i][j] != '\n')
			{
				if (game->map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		else
		{
			if (check_chars(game, rows) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	check_map(char *map_name, t_game *game)
{
	game->rows = check_size(map_name, game);
	if (game->rows == -1)
		return (-1);
	if (create_map(map_name, game, game->rows) == -1)
		return (-1);
	if (check_values(game, game->rows) == -1)
	{
		free(game->map);
		return (-1);
	}
	return (1);
}
