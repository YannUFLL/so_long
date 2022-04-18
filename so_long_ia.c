/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:09:10 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/18 18:12:46 by ydumaine         ###   ########.fr       */
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

int	ft_check_wall_l(char **map, int c, int x, int y)
{
	if ((map[y][x + 1] == '1' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
			&& c == 2)
		return (1);
	if ((map[y][x - 1] == '1' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
			&& c == 8)
		return (1);
	if ((map[y - 1][x] == '1' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
			&& c == 6)
		return (1);
	if ((map[y + 1][x] == '1' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
			&& c == 4)
		return (1);
	return (0);
}

int	ft_check_wall_f(char **map, int c, int x, int y)
{
	if ((map[y][x + 1] == '1' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
			&& c == 6)
		return (1);
	if ((map[y][x - 1] == '1' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
			&& c == 4)
		return (1);
	if ((map[y - 1][x] == '1' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
			&& c == 8)
		return (1);
	if ((map[y + 1][x] == '1' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
			&& c == 2)
		return (1);
	return (0);
}

void	ft_ia(char **map)
{
	int			x;
	int			y;
	static int	sens;

	if (sens == 0)
		sens = 6;
	ft_get_posm(map, &y, &x);
	if (ft_check_wall_l(map, sens, x, y) && !ft_check_wall_f(map, sens, x, y))
	{
		ft_move(map, sens, x, y);
	}
	else if (!ft_check_wall_l(map, sens, x, y))
	{
		sens = ft_sens(sens, 'g');
		ft_move(map, sens, x, y);
	}
	else if (ft_check_wall_l(map, sens, x, y)
		&& ft_check_wall_f(map, sens, x, y))
	{
		sens = ft_sens(sens, 'd');
	}
}
