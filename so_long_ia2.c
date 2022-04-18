/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ia2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:07:41 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/18 18:13:21 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(char **map, int c, int x, int y)
{
	map[y][x] = '0';
	if (c == 6)
	{
		if (ft_check_player('r', map, x, y))
			ft_exit(map);
		map[y][x + 1] = 'M';
	}
	if (c == 4)
	{
		if (ft_check_player('l', map, x, y))
			ft_exit(map);
		map[y][x - 1] = 'M';
	}
	if (c == 8)
	{
		if (ft_check_player('u', map, x, y))
			ft_exit(map);
		map[y - 1][x] = 'M';
	}
	if (c == 2)
	{
		if (ft_check_player('d', map, x, y))
			ft_exit(map);
		map[y + 1][x] = 'M';
	}
}

int	ft_sens(int sens, char d)
{
	if (d == 'g')
	{
		if (sens == 8)
			sens = 4;
		else if (sens == 6)
			sens = 8;
		else if (sens == 2)
			sens = 6;
		else if (sens == 4)
			sens = 2;
	}
	if (d == 'd')
	{
		if (sens == 8)
			sens = 6;
		else if (sens == 6)
			sens = 2;
		else if (sens == 2)
			sens = 4;
		else if (sens == 4)
			sens = 8;
	}
	return (sens);
}
