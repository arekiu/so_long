#include "so_long.h"

void	count_collectables(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{

		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
				if (game->map[i][j] == 'C')
					game->collectables = game->collectables + 1;
				j++;
		}
		i++;
	}
}
int	check_other(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{

		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
				if (game->map[i][j] != 'C' && game->map[i][j] != 'E' \
					&& game->map[i][j] != 'P' && game->map[i][j] != '0' \
						&& game->map[i][j] != '1')
				{
					ft_printf("Invalid characters\n");
					return (-1);
				}
				j++;
		}
		i++;
	}
	return (1);
}

int	check_chars(t_game *game)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	len;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	len = (int)ft_strlen(game->map[0]) - 1;
	while (i++ < game->rows - 1)
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
	if ((p != 1) || (e != 1) || (c < 1) || check_other(game) == -1)
		return (-1);
	return (1);
}

int	check_values(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		if (i == 0 || i == game->rows - 1)
		{
			j = 0;
			while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
			{
				if (game->map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		else
		{
			if (check_chars(game) == -1)
				return (-1);
		}
		i++;
	}
	count_collectables(game);
	return (1);
}
