/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:09:10 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 20:48:34 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_posm(char **map, int *line, int *column)
{
	int	stop;
	int	x;
	int	y;

	y = 0;
	x = 0;
	stop = 0;
	while (map[y][x] && !stop)
	{
		while (map[y][x] && !stop)
		{
			if (map[y][x] == 'M')
				stop = 1;
			if (!stop)
				x++;
		}
		if (stop == 1)
			break ;
		x = 0;
		y++;
	}
	*line = y;
	*column = x;
}

int	ft_check_player(char c, char **map, int x, int y)
{
	if ((map[y][x + 1] == 'A' || map[y][x + 1] == 'D' || map[y][x + 1] == 'W'
			|| map[y][x + 1] == 'P') && c == 'r')
		return (1);
	if ((map[y][x - 1] == 'A' || map[y][x - 1] == 'D' || map[y][x - 1] == 'W'
			|| map[y][x - 1] == 'P') && c == 'l')
		return (1);
	if ((map[y + 1][x] == 'A' || map[y + 1][x] == 'D' || map[y + 1][x] == 'W'
			|| map[y + 1][x] == 'P') && c == 'd')
		return (1);
	if ((map[y - 1][x] == 'A' || map[y - 1][x] == 'D' || map[y - 1][x] == 'W'
			|| map[y - 1][x] == 'P') && c == 'u')
		return (1);
	return (0);
}

int	ft_check_no_wall(char **map, char c, int x, int y)
{
	if ((map[y][x + 1] != '1' && map[y][x + 1] != 'C' && map[y][x + 1] != 'E')
			&& c == 'r')
		return (1);
	if ((map[y][x - 1] != '1' && map[y][x - 1] != 'C' && map[y][x - 1] != 'E')
			&& c == 'l')
		return (1);
	if ((map[y - 1][x] != '1' && map[y - 1][x] != 'C' && map[y - 1][x] != 'E')
			&& c == 'u')
		return (1);
	if ((map[y + 1][x] != '1' && map[y + 1][x] != 'C' && map[y + 1][x] != 'E')
			&& c == 'd')
		return (1);
	return (0);
}

void	ft_move(char **map, char c, int x, int y)
{
	map[y][x] = '0';
	if (c == 'r')
	{
		if (ft_check_player('r', map, x, y))
			ft_exit(map);
		map[y][x + 1] = 'M';
	}
	if (c == 'l')
	{
		if (ft_check_player('l', map, x, y))
			ft_exit(map);
		map[y][x - 1] = 'M';
	}
	if (c == 'u')
	{
		if (ft_check_player('u', map, x, y))
			ft_exit(map);
		map[y - 1][x] = 'M';
	}
	if (c == 'd')
	{
		if (ft_check_player('d', map, x, y))
			ft_exit(map);
		map[y + 1][x] = 'M';
	}
}

void	ft_ia(char **map, int *k)
{
	int			x;
	int			y;
	static int	u;

	ft_get_posm(map, &y, &x);
	if (ft_check_no_wall(map, 'r', x, y) && *k == 1)
		ft_move(map, 'r', x, y);
	if (ft_check_no_wall(map, 'd', x, y) && *k == 3)
		ft_move(map, 'd', x, y);
	if (ft_check_no_wall(map, 'u', x, y) && *k == 2)
		ft_move(map, 'u', x, y);
	if (ft_check_no_wall(map, 'l', x, y) && *k == 4)
		ft_move(map, 'l', x, y);
	u++;
	if (*k > 6)
		(*k = (u % 10));
}
