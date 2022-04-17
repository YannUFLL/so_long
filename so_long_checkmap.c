/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:24:17 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 20:30:23 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(char **map)
{
	int	i;
	int	u;
	int	control;

	i = 0;
	u = 0;
	while (map[0][i])
		i++;
	control = i;
	map++;
	while (map[u])
	{
		while (map[u][i])
			i++;
		if (control != i)
			return (1);
		u++;
	}
	return (0);
}

int	ft_check_wall(char **map)
{
	int	length;
	int	u;

	length = 0;
	u = 0;
	while ((map[0][length]))
	{
		if (map[0][length] != '1')
			return (1);
		length++;
	}
	while (map[u + 1] != NULL)
	{
		if (map[u][0] != '1' || map[u][length - 1] != '1')
			return (1);
		u++;
	}
	length = 0;
	while (map[u][length])
	{
		if (map[u][length] != '1')
			return (1);
		length++;
	}
	return (0);
}

int	ft_check_item(char **map)
{
	t_cep	cep;

	cep.i = 0;
	cep.c = 0;
	cep.e = 0;
	cep.p = 0;
	while (map[cep.i])
	{
		cep.u = 0;
		while (map[cep.i][cep.u])
		{
			if (map[cep.i][cep.u] == 'E')
				cep.c = 1;
			if (map[cep.i][cep.u] == 'E')
				cep.e = 1;
			if (map[cep.i][cep.u] == 'P')
				cep.p = 1;
			cep.u++;
		}
		cep.i++;
	}
	if (cep.c == 1 && cep.e == 1 && cep.p == 1)
		return (0);
	return (1);
}

void	ft_put_monster(char **map)
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
			if (map[y][x] == '0')
			{
				map[y][x] = 'M';
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_check_map(char **map)
{
	if (map == NULL)
		return (1);
	if (ft_check_rectangle(map))
	{
		ft_printf("Error\nThe map is not rectangular.");
		return (1);
	}
	if (ft_check_wall(map))
	{
		ft_printf("Error\nThe map is not wall framed");
		return (1);
	}
	if (ft_check_item(map))
	{
		ft_printf("Error\nMissing items");
		return (1);
	}
	ft_put_monster(map);
	return (0);
}
