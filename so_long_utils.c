/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:01:46 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 21:32:59 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_pos(char **map, int *line, int *column)
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
			if (map[y][x] == 'W' || map[y][x] == 'A' || map[y][x] == 'P'
					|| map[y][x] == 'D')
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

void	ft_if_items(t_data *data, int line, int column, char a)
{
	if ((data->map)[line - 1][column] == 'C' && (a == 'w'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line - 1][column] == 'M' && (a == 'w'))
		ft_exit(data->map);
	if ((data->map)[line + 1][column] == 'C' && (a == 's'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line + 1][column] == 'M' && (a == 's'))
		ft_exit(data->map);
	if ((data->map)[line][column - 1] == 'C' && (a == 'a'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line][column - 1] == 'M' && (a == 'a'))
		ft_exit(data->map);
	if ((data->map)[line][column + 1] == 'C' && (a == 'd'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line][column + 1] == 'M' && (a == 'd'))
		ft_exit(data->map);
}

void	ft_print_footsteps(t_data *data, char a)
{
	static int	foot;
	char		*ptr;

	if (a == '+')
		foot = foot + 1;
	ptr = ft_itoa(foot);
	mlx_string_put(data->mlx, data->win, 10, 15, 0x00FFFFFF, "Nombre de pas :");
	mlx_string_put(data->mlx, data->win, 170, 15, 0x00FFFFFF, ptr);
	free(ptr);
}

int	ft_if_end(t_data *data, int line, int column)
{
	if ((data->map)[line][column] == 'E' && *data->collect == 0)
		ft_exit(data->map);
	else if ((data->map)[line][column] == 'E')
		return (1);
	else
		return (0);
	return (0);
}

int	ft_number_item(char **map)
{
	int	u;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		u = 0;
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				c++;
			u++;
		}
		i++;
	}
	return (c);
}
